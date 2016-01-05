// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
#define FATEMARK "����B/��ɽ_�ƺ�"
inherit ROOM;
void create()
{
        set("short", "�춼��");
        set("long", @LONG
�춼��������������Ϊ�վ���һ�����ųơ�Ⱥ������������Ϊ���϶��ᡣ����
·��������ɽ��͵�ʯ��������Χ���ĵ�ɽ����������Ȼ�����С����������족֮
�С�;����һʯ���磬���С��������������֣��ɴ˴��������������ƹַ壬ɽȪ
�ɺ��������۵ס�
LONG
        );
	set("exits", ([ 
		"southdown"  : __DIR__"jiyu",
		"westdown" : __DIR__"yixian",
	]));
	set("objects", ([
		__DIR__"npc/hong" : 1,
		__DIR__"npc/lu" :1,
	]) );
    	set("outdoors", "huangshan");
      	set("coor/x",-50);
      	set("coor/y",40);
	set("coor/z",40);
	setup();
}

void init_scenery()
{
    	if(NATURE_D->get_weather() == "��")
    	{
		remove_call_out("cloud");
		call_out("cloud", 2);
    	}
}


void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if (random(ob->query("kar"))>15) {
		tell_object(ob,HIW"\n��һʱ������յ�����֮�У����ƺ���ʧ�˷����Ҳ�����·��Ҳ�Ҳ���ȥ·�ˡ�\n"NOR);
		if(ob->query_busy()<3)		ob->start_busy(2+random(2));
		ob->set(FATEMARK, num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void cloud()
{
	int i, age;
	object ob = this_object();
	object *ppls;
	function f=(:add_fate_mark:);
	message("vision", HIW"ͻȻ������󺣳�һ��ӿ����ת�����ܶ��ǰ�ãã����\n"NOR, ob);
	ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
	if(sizeof(ppls))
		map_array(ppls,f);
}
