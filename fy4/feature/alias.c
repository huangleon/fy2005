// alias.c

#define MAX_REPEAT 60
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
#define MAX_IN_A_ROW 20
mapping alias;

static string *history, last_input;
static int last_cmd, repeat_cnt = 0;
static int last_check, maxcom  = 0; 
string process_input(string str)
{
	string *args, cmd, argstr;
	int i, j;
	object room;
	if(this_object()->query_temp("disable_inputs"))
	return "ʲ�᣿\n";
	if(maxcom == 0)	last_check = time();
	if(maxcom == (MAX_IN_A_ROW -1 ) && time() == last_check)
	return "";
	else
	maxcom++;
	maxcom = maxcom % MAX_IN_A_ROW ;
	if( str==last_input ) {
		repeat_cnt++;
/*
		if((repeat_cnt > MAX_REPEAT)&& !wizardp(this_object()) 
		&& !this_object()->is_fighting()) {
		message_vision("��Ȼһ��������ס��$N��\n",this_object());
        	this_object()->set_temp("last_location", base_name(environment(this_object())));
		tell_object(this_object(),"�㱻����Ϊ�����ˣ�\n");
        	room = load_object(AREA_WIZ"courthouse");
        	this_object()->move(room);
		repeat_cnt = 0;	
		}
*/
	} else {
		repeat_cnt = 0;
		last_input = str;
	}

	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			else
				str = history[last_cmd];
		} else
			return "";
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}

	if( mapp(alias) ) {

		if( !undefinedp(alias[str]) )
			return replace_string( alias[str], "$*", "" );

		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
			return cmd;
		}
	}

	return (string)ALIAS_D->process_global_alias(str);
}

int set_alias(string verb, string replace)
{
	if( !replace ) {
		if(mapp(alias) ) 
		{
			if (member_array(verb, keys(alias))!= -1)
			{
				map_delete(alias, verb);
				write(sprintf("ȥ�� alias ��%s \n", verb));	
			}
			else
				write(sprintf("�㲻��������� alias ��%s \n", verb));	
		}
		return 1;
	} else {
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("���趨�� alias ̫���ˣ�����ɾ��һЩ�����õġ�\n");
		else 
		{
			alias[verb] = replace;
			write(sprintf("�趨��%s ����%s \n", verb,replace));	
		}
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}

