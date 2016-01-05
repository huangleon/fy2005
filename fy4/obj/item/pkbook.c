#include <ansi.h>
inherit ITEM;
string desc();

void create()
{
    	set_name("������Լ", ({ "book"}) );
    	set_weight(5);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("no_split", 1);
        	set("long",(: desc():));
        	set("value", 0);
        	set("desc_ext","�޼�֮�����ܻ���ʲô�أ�");
    	}
    	::init_item();
}


void init()
{
 	if (environment() && userp(environment())	{
 		add_action("do_mutate", "mutate");
 		add_action("do_setname", "setname");
	}
}

int check_legal_name(object me, string name)
{
	int i;
	string tempname;

	i = strlen(name);

	if( (strlen(name) < 2) || (strlen(name) > 10 ) )
	{
		tell_object(me, "�Բ�������������ֱ�����һ����������֡�\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			tell_object(me, "�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			tell_object(me, "�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	return 1;
}

int	do_setname(string arg){
	object me;
	
	me = this_player();
	
	if (stringp(me->query("dark_assassin/name"))) {
		tell_object(me,"���ɱ�ִ���Ϊ"+ me->query("dark_assassin/name")+"��\n");
		return 1;
	}
	
	if(me->query_temp("char_encoding") == "big5") {
		arg = ENCODE_D->big5Togb(arg);
	}
	if( !check_legal_name(me, arg) || arg == "����")
	{
		return 1;
	}
	
	me->set("dark_assassin/name",arg);
	tell_object(me, "�ã��������ڵĴ��ŴӴ�Ϊ"+arg+"��\n");
	return 1;
}

	