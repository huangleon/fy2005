#include <ansi.h>
inherit ROOM;

int blinding(object me);
int bbqthem(object me, object obj);

void create()
{
        set("short", "̫ƽ�ӻ���");
        set("long", @LONG
̫ƽ�ӻ���ʵ���Ǹ����׼׼�������̣�ˢǽ�İ׷ۣ���ɫ������ͩ�ͺ��ᣬ
���ǣ����������ף�С�ף�������Ѽ�������ۣ����ߣ�Ь�ӣ���ƥ�����̣��Ͼơ���
ֻҪ������õ��Ķ��������ﶼ�У������벻���Ķ������ﶼ�С�һ��ô�ô��
������������廨���ţ���ʽ�����Ķ�������������һ������������ĵ�ǹ����
һ�����װ�ľɻ���
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"mroad3",
	]));
        set("item_desc", ([
	
	 ]));
	 set("objects", ([
               	__DIR__"npc/oldworm" : 1,
    	]) );
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

	
int blinding(object ob) {
	object *enemy;
	enemy=ob->query_enemy();
	if (!enemy || sizeof(enemy)<1)	return 1;
	message_vision(HIW"\n$N��Ȼһ���ֶ���һ��ʯ�ң��׷۷�ɢ������һ����ʱ������������������֮�С�\n"NOR,ob);
	foreach (object x in enemy) {
		if (x->query_temp("block_msg/all")) continue;
		bbqthem(ob,x);
	}
	return 1;
}

int bbqthem(object me, object enemy) 
{
	if(enemy->query("combat_exp")>random(me->query("combat_exp")*5))
        {
        	message_vision(HIB"$N��æת��ͷȥ���ܿ��׷ۡ�\n"NOR,enemy);
        	return 1;
        }
	tell_object(enemy,HIW"��ֻ������ǰ��ãã��һƬ��ʲô���������ˡ�����\n"NOR);
	enemy->add_temp("block_msg/all",1);
	message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n"NOR,enemy);
	call_out ("recover",10, enemy);
	return 1;
}


int recover (object obj){
	if (!obj)	return 1;
	if (obj->query_temp("block_msg/all")>=1)
	    	obj->add_temp("block_msg/all", -1);
	tell_object(obj, HIG"���������ģ�����۾���ʼ���Էֱ���Χ�������ˡ�\n" NOR);
	return 1;
}	
