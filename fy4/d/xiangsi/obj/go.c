// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ʯ��", ({ "desk", "stone desk","table","ʯ��" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","on");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ��ʯ�Ƶ����̡�\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


void init()
{
	add_action("do_look", "look");
}

int do_look(string arg)
{
	object me;
	int i,line;
	string *text,*text2;
	me = this_player();
	if(!arg || present(arg,environment()) != this_object())
		return 0;
	write("ʯ���Ϻ������ˣ����ǿ���һ�����̣�");
	if (file_size("/d/xiangsi/icecave-maze.map") < 1 || file_size("/d/xiangsi/icecave2-maze.map") < 1)
	{
		write("�������������ϣ����ܿ��������\n");
		return 1;
	}
	write("������ȥ��ֻ�����Ͽ��ţ�\n\n");
	text = explode(read_file("/d/xiangsi/icecave-maze.map"), "\n");
	text2 = explode(read_file("/d/xiangsi/icecave2-maze.map"), "\n");
	for(line =1 ; line<sizeof(text); line++)
	{
		for (i=39; i>6; i-=2)
			write(""+text[19-line][i .. i+1] + "");
		for (i=39; i>6; i-=2)
			write(""+text2[19-line][i .. i+1] + "");
		write("\n");
	}
	return 1;
}

    
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
