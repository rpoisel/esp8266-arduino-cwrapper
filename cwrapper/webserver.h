/*
 * webserver.h
 *
 *  Created on: Jan 30, 2016
 *      Author: rpoisel
 */

#ifndef WEBSERVER_H_
#define WEBSERVER_H_

#ifdef __cplusplus
extern "C" {
#endif

void webserver_start(void);
void webserver_set_root_data(const char* data);
void webserver_loop(void);

#ifdef __cplusplus
}
#endif


#endif /* WEBSERVER_H_ */
