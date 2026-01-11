import json

def lambda_handler(event, context):
    return {
        "statusCode": 200,
        "body": json.dumps({"speed": 60, "battery": 80})
    }

