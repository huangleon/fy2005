inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ֱ����");
        set("long", @LONG
ֱ����Ϊ���ص�������֮һ����ľ��ͽ��죬���ڴ��пں������������ݵ���
�ܵ���һ�𡣸��¹�ľ���죬�ɰس��࣬�������ţ��������ﻨ�㡣��Ⱥ��ӵĲ�
���洦�ɼ����������������������𲻶ϣ�ǰ����ʥ�����䲻����
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"wild6",
		
	]));
        set("item_desc", ([
        	"tree":	"ֱ���¹�ľ���죬ÿ�ö����ϰ������ʷ��\n",
        	"��ľ":	"ֱ���¹�ľ���죬ÿ�ö����ϰ������ʷ��\n",
        	"�ɰ�":	"���������Ͱ����ˡ�����\n",
        	"����": "�������ߣ�����ĳɹ���״��\n",
        	"pine": "������������ڽ��µ��������µģ�������Ѿ֦�����εĴ�Ҷ����ס�˰����ա�\n",
        	"����": "������������ڽ��µ��������µģ�������Ѿ֦�����εĴ�Ҷ����ס�˰����ա�\n",
    	]));
        
        set("objects", ([
        	__DIR__"npc/chicken":	2,
        	__DIR__"obj/statue5":	1,
        	__DIR__"npc/monk5":	1,
	]) );
        set("coor/x",-1900);
        set("coor/y",720);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

void init(){
	add_action("do_around","around");
	add_action("do_climb","climb");
}

void reset()
{
	object statue,incense;
               
        ::reset();
        statue = present("statue", this_object());
        if (!present("incense",statue)) {
        	incense=new(__DIR__"obj/incense");
        	incense->move(statue);
	}
}


int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg) {
		tell_object( me, "������ʲô��\n");
		return 1;
	}
	
	if (arg == "tree" || arg == "��"){
		tell_object( me, "�ţ���ô���Ŀ����أ�\n");
		return 1;
	}
		
	if (arg=="pine"|| arg=="����" || arg == "������") {
//		if (!me->query_temp("marks/zangbei/������")) 
//			return notify_fail("��Ե�޹���ʲô����\n");
		room=find_object(__DIR__"pine1");
		if (!objectp(room)) room=load_object(__DIR__"pine1");
		message_vision("$N�ֽŲ��ã����ݵ�������������\n",me);
        tell_room(room, this_player()->name() + "����������������\n");
        this_player()->move(room);
      	return 1;
      }
      
      return notify_fail("������û������\n");
}

int do_around(){
	
	object me = this_player();
	object tong = me->query_temp("weapon");
	
	
	if (!tong || tong->name() != "ת��Ͳ")
		return notify_fail("û�о�Ͳ�����ת����\n");
	
	if (me->is_busy())
		return notify_fail("������æ�úܣ�û��ת����\n");
				
	message_vision(YEL"$Nת�������е�С��Ͳ���ϵ����ž��ģ�����"
		+this_object()->query("short") + "��������һȦ��\n"NOR, me);
	me->start_busy(1);
	
	if (me->query("marks/ת��") ||
		REWARD_D->riddle_check(me,"��ͯת��")!=1
		|| me->query_temp("zhuanjing/zhigong"))	return 1;
		
	me->add_temp("zhuan_around",1);
	
	if (random (me->query_temp("zhuan_around"))>= 10)
	{
		tell_object(me,WHT"\n����"+ query("short")+"ת����ϣ������ڷ𷨵��˽�������ߡ�\n"NOR);	
		me->delete_temp("zhuan_around");
		me->set_temp("zhuanjing/zhigong",1);
		
		if (mapp (me->query_temp("zhuanjing")))
		if (sizeof(me->query_temp("zhuanjing")) == 4)
		{
			REWARD_D->riddle_set(me,"��ͯת��",2);
			me->set_skill("lamaism",me->query_skill("lamaism",1)+1);
			tell_object(me,HIC"������ڷ������һ���ȼ���\n"NOR);			
			me->set("marks/ת��",1);
			me->delete_temp("zhuanjing");
		}
	}
	return 1;
}
	
	