// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "����ի");
    set("long", @LONG
�߽��˴�������ͷ��Ȼһ�����������¥���������Ĵ󺣣���֪��
��ի���޷����򵥵İ��Σ�Ψһ�ıڹ���Ϸŵ��Ǹ�ʽ����������ݵľƣ���
�ϸ�����һ��ѩɫ�İٺϻ���ǽ��һ��ˮī������һͷ�̾��ڴ��ԭ�ϣ�����
��צ����Х˻����׳���������·������찿��Ĵ��״󻢡�
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/song":1,
	__DIR__"npc/zhou":1,

	__DIR__"obj/cabin":1,

	]));
	set("item_desc", ([
	"�ٺϻ�":"һ��ѩɫ�İٺ����������š�\n",
	"�ٺ�":"һ��ѩɫ�İٺ����������š�\n",
	"��":"һ��ѩɫ�İٺ����������š�\n",
	"lily":"һ��ѩɫ�İٺ����������š�\n",
	"flower":"һ��ѩɫ�İٺ����������š�\n",

	
	]) );
	set("exits",([
  		"east" : __DIR__"bridge",
	]) );

	set("no_lu_letter",1);
	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}


void reset()
{
	object river,stone,*inv;
	
	::reset();



	river = present("�ڹ�", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1 )
	{
		stone = new(__DIR__"obj/wine5");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/wine1");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/wine2");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/wine3");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/wine4");
		if(stone)
			stone->move(river);
	}


	return;
}

void init() {
	add_action("do_pick","pick");
	add_action("do_get","get");
}

int do_get(string arg)
{
    string what,where;
    object the_wall;
	object ye,ye1;
	object me = this_player();
	ye=present("zhou zimo",this_object());
	ye1=present("song qiuchen",this_object());
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,this_object()) ;
    if (the_wall)
    if(the_wall->query("name") == "�ڹ��")       
    {
		if (ye)
		{
			message_vision("$N��ü������λ" + RANK_D->query_respect(me)+"���벻Ҫ�ڹ��컯���¹�Ȼ���ԡ�\n",ye);
			return 1;
		}
		if (ye1)
		{
			message_vision("$N��ü������λ" + RANK_D->query_respect(me)+"���벻Ҫ�ڹ��컯���¹�Ȼ���ԡ�\n",ye1);
			return 1;
		}
    }
    return 0;
}


int do_pick(string arg)
{
	object me = this_player();
	string arg1,arg2;
	int num,gao;
	object ye,ye1;
	ye=present("zhou zimo",this_object());
	ye1=present("song qiuchen",this_object());
	if (!ye && !ye1)
		return notify_fail("����ǰһ�����Ƕ仨��Ȼ�����ˡ�\n");
	if (!arg)
		return notify_fail("��Ҫժʲô��");
	if (arg != "�ٺϻ�" && arg != "�ٺ�" && arg != "flower" && arg != "��" && arg != "lily")
		return notify_fail("��Ҫժʲô��");
	if (ye)
	{
		message_vision("$N��ü������λ" + RANK_D->query_respect(me)+"��ĪҪ���ִݻ���\n",ye);
		return 1;
	}
	if (ye1)
	{
		message_vision("$N��ü������λ" + RANK_D->query_respect(me)+"��ĪҪ���ִݻ���\n",ye1);
		return 1;
	}
	return 0;
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


