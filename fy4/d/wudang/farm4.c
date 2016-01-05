#define FATEMARK "����B/�䵱_��Ҷ"
inherit ROOM;
#include <ansi.h>



void create()
{
	set("short", "ׯ�ڵ�");
	set("long", @LONG
һ�������͵�������а��˸ߵ���˶������������罭���е��㣬������
��֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,������Ȼ���¡� 
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"farm4",
		"south" : __DIR__"farm2",
		"east" : __DIR__"farm4",
		"west" : __DIR__"farm6",
	]));
	set("outdoors", "wudang");
	set("coor/x",20);
	set("coor/y",60);
	set("coor/z",-50);
	setup();

}

void init()
{
	add_action("do_throw","throw");
}

int wind_blow(object me)
{
	object room;
	string weather;
	room = this_object();
	weather = NATURE_D->get_weather();
	
	if(weather != "΢��" && weather != "���" && weather != "���" ) 
		return 1;
	message("vision",HIG"
    ����΢������������ʲô��Ҷ֮�����(throw)�ڿ��еĻ���һ������
��Ʈȥ�����һ�����Ƿ�Ҳ������Ҷһ�㣬���Ʈ����\n"NOR,room);
	return 1;
}

int do_throw(string arg)
{
	string leaf_name, weather;
	object leaf,ob;
	int num= 1+random(10);
	
	ob = this_player();
	
	if(!arg) return notify_fail("��Ҫ��ʲô��\n");
	leaf = present(arg, this_player());
	if(!leaf)
		return notify_fail("��û���������ѽ��\n");
	if(!leaf->query("castable"))
		return notify_fail("��������ײ�������\n");
	weather = NATURE_D->get_weather();
	if(weather != "΢��" && weather != "���" && weather != "���" ) 
		return notify_fail("����û�з磬�ײ�������\n");
	if(this_player()->query("age")>13 || this_player()->query("����B/�䵱_��Ҷ",1))
		return notify_fail("���Ѿ�����С�����ˡ�\n");
	leaf_name=leaf->query("name");
	message_vision("$N��һƬ"+leaf_name+NOR"���ڷ��У�������Ʈ���ˡ�\n",this_player());
	if(leaf_name==HIR"��Ҷ"NOR)
	this_player()->set("����B/�䵱_��Ҷ", num);
	log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�����B/�䵱_��Ҷ "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	destruct(leaf);
	return 1;
}
		

void init_scenery()
{
        remove_call_out("wind_blow");
        call_out("wind_blow",1);
}
