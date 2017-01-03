/*
 * Copyright (C) 2016 Team Win Recovery Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ext4crypt_tar.h"

#define EXT4_KEY_DESCRIPTOR_SIZE 8
#define EXT4_KEY_DESCRIPTOR_SIZE_HEX 17

int main(int argc, char *argv[]) {
	bool ret = false;
	if (argc != 2) {
		printf("Must specify a path\n");
		return -1;
	} else  {
		char e4crypt_policy[EXT4_KEY_DESCRIPTOR_SIZE];
		if (e4crypt_policy_get(argv[1], e4crypt_policy, EXT4_KEY_DESCRIPTOR_SIZE, 0))
		{
			char* ptr = tar_policy;
			memset(tar_policy, 0, sizeof(tar_policy));
			char policy_hex[EXT4_KEY_DESCRIPTOR_SIZE_HEX];
			policy_to_hex(e4crypt_policy, policy_hex);
			printf("%s\n", policy_hex);
		} else {
			printf("No policy set\n");
		}
	}
	return 0;
}
