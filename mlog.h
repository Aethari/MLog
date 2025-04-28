/*
 * Single header C logging library
 * See README.md for more info
 * See LICENSE.txt for license info
 * 2025 DJaySky (github.com/DJaySky)
 */

#ifndef MLOG_H
#define MLOG_H

/// The path to the log file.
char log_path[1000]

/// Creates a log file at the directory of the running application.
/// Should only be called once, at the top of the main function.
/// Sets log_path to the absolute path of the file created.
void log_init();

/// Clears the log file, sparing no content
void log_clear();

/// Writes a message to the log file
///
/// Parameters:
/// - msg: The message to be written to the log file
void log_write(char msg[]);

/// Writes a message to the log file and prints to the terminal
///
/// Parameters:
/// - msg: The message to be written to the log file and printed to the terminal
void log_pwrite(char msg[]);

#endif

#ifdef MLOG_IMPL

#ifdef __unix__
	#include <unistd.h>
#elif _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX
	#include <windows.h>
#endif

void log_init() {
	// get the absolute path to the directory of the running exe
	char exe_path[1000];

	#ifdef __unix__
		ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path)-1);
		exe_path[len] = '\0';
	#elif _WIN32
		GetModuleFileNameA(NULL, exe_path, 1000);
	#endif
	strcpy(log_path, exe_path);
	strcpy(log_path, dirname(log_path));

	strcat(log_path, "/log.txt");
}

void log_clear() {
	FILE *log_file = fopen(log_path, "w");
	fclose(log_file);
}

void log_write(char msg[]) {
	FILE *log_file = fopen(log_path, "a");
	fwrite(msg, strlen(msg), 1, log_file);
	fclose(log_file);
}

void log_pwrite(char msg[]) {
	printf(msg);
	log_write(msg);
}

#endif
