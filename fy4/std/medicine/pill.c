// pill.c

inherit COMBINED_ITEM;

void setup()
{
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");
	
}

