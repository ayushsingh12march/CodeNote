## class -> query, engine_decider()
 ## spark_engine(), hive_engine() 
 ############
#  spark -> spark_engine() -> job_execute()
#  hive -> hive_engine()
#  emr -> emr_engine()

def spark(partition,query):
    print("hello world")

class EngineDecider:
    parameters = {}
    engine = {}

    def __init__(self, **kwargs):
        for key,val in kwargs.items():
            self.parameters[key] = val


    def engine_entry(self,name,fn_name):
        self.engine[name] = fn_name

    def engine_decider(self, query : str):
        # spark
        if "select" in query:
            # parameters
            if self.parameters.get("partition") == None:
                raise Exception("parttition isrequired")
            
            partition = self.parameters.get("partition")
            self.engine.get("pyspark")(partition,query)

        # emr

if __name__ == '__main__':
    e = EngineDecider(partition=2)
    e.engine_entry("pyspark",spark)
    e.engine_decider("select * from tables")
