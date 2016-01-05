#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "��ˮ���ֶ�");
        set("long", @LONG
��������ˮ�����ֶܷ�֮һ���������Ѿ����������ˡ������ƺ���һ��
ʯ�������ڷ���һ�齸�ң���Χ������ˮ�ݣ�ȴ������Ϻ�ζ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"bottom2",
  "south" : __DIR__"bao2",
]));
	set("coor/x",-50);
	set("coor/y",60);
	set("coor/z",0);
	setup();

	set("item_desc", ([
		"south" : "���ҳ��׽����ڷ�ס�ˡ�\n",
	]) );

	set("underwater",30);
	set("water_damage",2);

	set("no_fly", 1);
	set("max_lv",20);	// ��ֹ20�����Ͻ�ɫ����
	set("min_lv",5);
}


int	valid_leave(object who, string dir)
{
	if (dir == "south" && present("moss rock",this_object()))
		return notify_fail("���ҳ��׽����ڷ�ס�ˡ�\n");
	return ::valid_leave(who,dir);
}

void init(){
	object me = this_player();
	object exitroom = find_object(__DIR__"bottom2");
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
	if (!exitroom)
		exitroom = load_object(__DIR__"bottom2");
	if (userp(me))
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv")
		|| exp_to_level(me->query("combat_exp"))["level"] <= query("min_lv"))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,HIB"һ����ӿ��������������ˮ���ֶ档\n"NOR);
	}


}
