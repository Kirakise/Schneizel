#ifndef PARSER_H
# define PARSER_H

int parsefile(char *s);
int parseline(char *s);
int ParseRes(char *s);
int ParseAmb(char *s);
int ParseCam(char *s);
int ParseLight(char *s);
int ParseSphere(char *s);
int ParsePlane(char *s);
int ParseSquare(char *s);
int ParseCylinder(char *s);
int ParseTriangle(char *s);
#endif