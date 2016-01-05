inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "������");
        set("long", @LONG
�����½ṹ���أ�����ׯ�أ����ֱܷ��аס��ơ��졢�����������ڳ��Ƴ�
ҹ��Ϣ���ķ�����Χ���������͸�������ֻ�����������������Ż��̴�ʼ��
Ѧ�Ȱ��Ǵ�������Ҳ�ר������ഫ�ĳɹ������ʱ�����ġ��������ס���Ҳ
�������̫�ɵ�Ե�ʣ��������ϡ�٣������Ѿ���Ϊ���䡣
LONG
        );
        set("exits", ([ 
		"northup" : __DIR__"mount2",
		
	]));
	set("item_desc", ([
        	"tower": 	"ש�������������ֱ�Ϊ�ס��ơ��졢����ɫ��\n",
        	"��������": 	"ש�������������ֱ�Ϊ�ס��ơ��졢����ɫ��\n",
        	"����": 	"ש�������������ֱ�Ϊ�ס��ơ��졢����ɫ��\n",
        	"red tower":	"һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
        	"yellow tower": "һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
        	"white tower":	"һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
        	"����":		"һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
        	"����":		"һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
        	"����":		"һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
    	]));
	
        set("objects", ([
        	__DIR__"npc/monk2":	1,
        	__DIR__"obj/statue2":	1,
	]) );
        set("coor/x",-1700);
        set("coor/y",590);
        set("coor/z",15);
	set("map","zbwest");
        set("item",1);
	setup();

}

void init(){
	add_action("do_look","look");
	add_action("do_around","around");
}

int do_look(string arg) {
	object me=this_player();
	object item;
	
	if (arg== "hole" || arg == "ǳѨ") {
		if (!me->query_temp("zangbei/������ש��")) 
			return notify_fail("��Ҫ��ʲô��\n");
			if (me->query("kar")< 12)
				return notify_fail("�����ֽ�ȥ������һ��һ��С��ץ��һ����࣬��������̫���ˣ�\n");
         	if (query("item")) {
				tell_object(me,"�ײ�������ֽ�ȥ������һ���õ�һ��ӲӲ�Ķ�����\n");
				if (random(3))
					item = new(__DIR__"obj/t_item2");
				else
					item = new(__DIR__"obj/annie_item");
         		        		
         		item->move(me);
         		set("item",0);
         	} else 
         		tell_object(me,"�ײ�������ֽ�ȥ������һ�������ǿյġ�\n");
		return 1;
	}
	if (arg == "green tower" || arg == "����") {
		tell_object(this_player(),"һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",);
		if (!me->query_temp("zangbei/������ʩ��")) 			
			return 1;
		tell_object(me,"��ϸ��ȥ��������������˵��������שʯ�Ѿ��ǳ���ɢ�����ط��������˼��飬
¶������ǳѨ������壩��\n");
		me->set_temp("zangbei/������ש��",1);
		return 1;
	}
	return 0;
}


void reset(){
	set("item",1);
	::reset();
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
	
	if (me->query("marks/ת��")
		||	REWARD_D->riddle_check(me,"��ͯת��")!=1
		|| me->query_temp("zhuanjing/tagong"))	return 1;
		
	me->add_temp("zhuan_around",1);
		
	if (random (me->query_temp("zhuan_around"))>= 10)
	{
		tell_object(me,WHT"\n����"+ query("short")+"ת����ϣ������ڷ𷨵��˽�������ߡ�\n"NOR);	
		me->delete_temp("zhuan_around");
		me->set_temp("zhuanjing/tagong",1);
		
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
	
	