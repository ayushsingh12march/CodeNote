import java.util.LinkedList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Solution {
    private HashMap<String, Table> _tablemap = new HashMap<String, Table>();
    private static Solution _ex = new Solution();

    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(System.in);
            while (true) {
                String line = scan.nextLine();
                if (line == null || line.length() == 0) {
                    continue;
                }
                System.out.println(line);
                Command command = Command.getCommand(line.split(" +")[0]);
                command.run(line);
                if (command == Command.END)
                    break;
            }
            _ex._tablemap.clear();
            scan.close();
        } catch (Throwable t) {
            t.printStackTrace();
        }
    }
    
    enum Command {
        INSERT {
            @Override
            void run(String line) throws Exception {
                String regex = "((?<=(INSERT\\sINTO\\s))[\\w\\d_]+(?=\\s+))|((?<=\\()([\\w\\d_,]+)+(?=\\)))";
                Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
                Matcher matcher = pattern.matcher(line);
                String table = "";
                LinkedList<String> columns = new LinkedList<String>();
                LinkedList<String> values = new LinkedList<String>();
                HashMap<String, String> columnMap = new LinkedHashMap<String, String>();
                if(matcher.find()) table = matcher.group(0);
                if(matcher.find()) columns = new LinkedList<String>(Arrays.asList(matcher.group(0).split(",")));
                if(matcher.find()) values = new LinkedList<String>(Arrays.asList(matcher.group(0).split(",")));
                for (int i=0; i<columns.size(); i++) {
                    columnMap.put(columns.get(i), values.get(i));
                }

                Table currTable = _ex._tablemap.get(table);
                if (currTable == null) {
                        currTable = _ex.new Table(table);
                        _ex._tablemap.put(table, currTable);
                }
                Row currRow;
                Row updateRow;
                boolean isUpdate=false;
                if (columnMap.containsKey("ID")) {
                    currRow = _ex.new Row(currTable, columnMap.get("ID"));                    
                } else {
                    System.out.println("INSERT requires ID");
                    return;
                }
                columns.stream().filter((i) -> {return !i.equals("ID");})
                    .forEach((i) -> {currRow.add(i, columnMap.get(i));});
                currTable.add(currRow);
                System.out.println("1 row inserted");
            }
        },
        LIST {
            @Override
            void run(String line) throws Exception {
                _ex._tablemap.keySet().stream().forEach((i) -> {System.out.println(i);});
            }
        },
        SELECT {
            @Override
            void run(String line) throws Exception {
                String regex = "((?<=(SELECT\\s))[\\w\\d_,]+(?=\\s+))|((?<=(FROM\\s))[\\w\\d_]+)";
                Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
                Matcher matcher = pattern.matcher(line);
                String table = "";
                LinkedList<String> columns = new LinkedList<String>();
                if(matcher.find()) columns = new LinkedList<String>(Arrays.asList(matcher.group(0).split(",")));
                if(matcher.find()) table = matcher.group(0);

                Table currTable = _ex._tablemap.get(table);
                if (currTable == null) {
                    System.out.println(table + " doesn't exist");
                    return;
                }
                int count = 0;
                LinkedList<String> fcolumns = columns;
                for (Row currRow : currTable.rows) {
                    if (fcolumns.contains("ID")) System.out.println("ID=" + currRow.id);
                    currRow.data.keySet().stream().filter((i) -> {return fcolumns.contains(i);})
                        .forEach((i) -> {System.out.println(i + "=" + currRow.data.get(i));});
                    count++;
                }                
                System.out.println(count + " row(s) selected");
            }
        },
        DELETE {
            @Override
            void run(String line) throws Exception {
                String regex = "((?<=(DELETE\\sFROM\\s))[\\w\\d_]+(?=\\s+))|((?<=(WHERE\\s))[\\w\\d_=]+)";
                Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
                Matcher matcher = pattern.matcher(line);
                String table = "";
                String column = "";
                String value = "";
                if(matcher.find()) table = matcher.group(0);
                if(matcher.find()) {
                    LinkedList<String> items = new LinkedList<String>(Arrays.asList(matcher.group(0).split("=")));
                    column = items.get(0); value = items.get(1);
                }
                
                Table currTable = _ex._tablemap.get(table);
                if (currTable == null) {
                    System.out.println(table + " doesn't exist");
                    return;
                }
                int count = 0;
                for (Row currRow : currTable.rows) {
                    if ((currRow.data.containsKey(column) && currRow.data.get(column).equals(value))) {
                            currTable.rows.remove(currRow);
                            count++;
                    }
                }
                System.out.println(count + " row(s) deleted");
                if (currTable.rows.isEmpty()) {
                    _ex._tablemap.remove(table);
                    System.out.println(table + " was deleted");
                }
            }

        },
        END {
            @Override
            void run(String line) throws Exception {
            }
        },
        INVALID {
            @Override
            void run(String line) throws Exception {
                System.out.println("Invalid Command " + line);
            }
        },
        ;
        abstract void run(String line) throws Exception;
        private static Command getCommand(String command) {
            for (Command target : values())
                if (target.toString().equals(command))
                    return target;
            return Command.INVALID;
        }
    }
    
    class Table {
        LinkedList<Row> rows = new LinkedList<Row>();
        String name;
        Table(String name) {
            this.name = name;
        }
        void add(Row row) {
            this.rows.add(row);
        }
    }
    class Row {
        HashMap<String, String> data = new LinkedHashMap<String, String>();
        Table table;
        String id;
        Row(Table table, String id) {
            this.table = table;
            this.id = id;
        }
        void add(String column, String value) {
            data.put(column, value);
        }
    }
}