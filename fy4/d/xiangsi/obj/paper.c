
inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
	set_name("���Ƶ�С����", ({"book"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����Ƶ�С���ӣ��ּ����þ��꣬�����ɼ�������ԼԼֻ�ֱܷ�������������壮�������������ۡ�\n");
		set("unit", "��");
		set("no_sell",1);
		set("no_pawn",1);
		set("no_stack",1);
		set("no_drop",1); 
		set("base_value", 0);
		set("base_unit", "��");
		set("base_weight", 50);
		set("illegal",1);
		set("volumn",1);
	}
	set_amount(1);
}

void init()
{
  if(this_player()==environment())
  	add_action("do_write","write");
}

int do_write(string arg)
{
	int i;
	i=atoi(arg);
	if (i>1000000)
		i=1;
	set("base_value",i);
	write("�㷭��С���ӣ�˳��д�£�"+arg+"\n");
	return 1;
}


