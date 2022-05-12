# Python 3 server example
from http.server import BaseHTTPRequestHandler, HTTPServer
import time
import logging
import settings
arg = "N"

hostName = str(settings.hostname)
serverPort = int(settings.port)

class MyServer(BaseHTTPRequestHandler):
    def do_GET(self, arg):
        self.send_response(200)
        self.send_header("Content-type", "text")
        self.end_headers()
        self.wfile.write(bytes(arg, "utf-8"))
        print("get")
        print(arg)
    
    def do_POST(self):
        content_length = int(self.headers['Content-Length']) # <--- Gets the size of data
        post_data = self.rfile.read(content_length) # <--- Gets the data itself
        logging.info("POST request,\nPath: %s\nHeaders:\n%s\n\nBody:\n%s\n",
                str(self.path), str(self.headers), post_data.decode('utf-8'))    
        print("post")
        print(post_data)
if __name__ == "__main__":        
    webServer = HTTPServer((hostName, serverPort), MyServer)
    print("Server started http://%s:%s" % (hostName, serverPort))

    try:
        webServer.serve_forever()
    except KeyboardInterrupt:
        pass

    webServer.server_close()
    print("Server stopped.")