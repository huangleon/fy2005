// Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h>

inherit DOOR_ROOM;

void create()
{
	set("short", "�е�");
	set("long", @LONG
�����ڴ���һ��խխ�ļе��ͨ�����·��һ���ʯ(rock)�������е���
���������ɸߵ�ʯǽ(wall)������������ϣ�ʯǽ�ϲ���������Բ��(hole)��ʯ
ǽ�ĺ��洫����֨֨�¸¡�������(noise)��
LONG
	);
	set("exits", ([ 
  "south" : __DIR__"gate_castle",
]));
        set("item_desc", ([
		  "wall" : "����һ�����ɸߣ��������ʯǽ��ǽ�ϵ�Բ�׺��ʺ�������������\n",
		  "rock" : "����һ��ǧ���ʯ����ס��ͨ�����·��\n",
		  "hole" : "��������Բ���￴����������̫���ˣ�ʲôҲ��������\n",
		  "noise": "����Ȼ������ǿ���������\n"
	]));

	set("outdoors", "chuenyu");

	create_door("south", "door","����", "north", DOOR_CLOSED);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}

void init()
{	object ob;
	if( interactive( ob = this_player())) {
		remove_call_out("arrowing");
		call_out("arrowing", 15, ob);
	}
}

int arrowing(object ob)

{
	int i;
	int damage;
        if( environment(ob) == this_object())
	{
		message_vision(HIW"ɲ�Ǽ�ʯǽ�ĺ��桰���ԡ������������������Բ������$N�����������\n", ob);
		message_vision("$N���Ҽ����ͷ��Ѫ�����������ˣ�\n"NOR, ob);
 		i = (int)ob->query("eff_kee");
		damage = random(10)+35	;
        	ob->set("eff_kee",(int) i - damage );
		i =  (int)ob->query("kee");
		ob->set("kee",(int) i - damage);
		ob->set("last_damage_from","�ں��ɱ������Ҽ����������\n");
		if( environment(ob) == this_object())
			call_out("arrowing",5, ob);	
	}
	else
		return 1;
}

int valid_leave(object me, string dir)
{
        remove_call_out("arrowing");
        return ::valid_leave(me,dir);
}

