inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "������");
        set("long", @LONG
��������һ������ͩq�����հ���һһ�����괴���ġ���Ժ��ɽ��ˮ���羰��
�������ڴ���һ�������հ����ܵ���һ�𣬴�ʦ��ǰ���µ��ּ�����Ѫ�һ�������
Ȼ�𾴡���������ɣ�Ѻ��У������Ⱥ������ɮ�˳����ָ����㱳��ι�����Ρ�
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"wild5",
		
	]));
        set("item_desc", ([
        	"��Ѫ�һ�":	"�����հ���ǰ���µ��ּ���\n",
        	"picture":	"�����հ���ǰ���µ��ּ���\n",
        	"�һ�":		"�����հ���ǰ���µ��ּ���\n",
    	]));
        
        set("objects", ([
        	__DIR__"obj/statue4":	1,
        	__DIR__"obj/river":	1,
        	__DIR__"npc/monk4":	1,
	]) );
         set("resource/water", 1);
    	set("liquid/container", "ɣ�Ѻ�");  
    	set("liquid/name","ɣ�Ѻ�ˮ");
    	
        set("coor/x",-1800);
        set("coor/y",720);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void reset()
{
	object statue,incense;
               
    ::reset();
   		
   	set("scepter",1);
   		
    statue = present("statue", this_object());
    if (!present("incense",statue)) {
      	incense=new(__DIR__"obj/incense");
    	incense->move(statue);
	}
}

void fish_notify(object obj){
   	object me, room, fish, *inv, bait;
	int i;
	
   	me = this_player();
	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
     		tell_object(me, obj->name() + "��û�ж���ô���Ե����� ? \n");		
		return;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      			message_vision("$N�Ӷ���һ��," + obj->name() + "�ڿ��л���һ��Ư���Ļ���, �㹳������ˮ��. \n" , me);
      			me->start_busy(5);
      			remove_call_out("do_fishing");              
      			call_out("do_fishing", 5, me, bait);			
			return;
		} 
	}
   	tell_object(me, "���õĶ���̫�԰� ? \n");			
	return;
}

void do_fishing(object me, object bait){
	object 	fish;
	int n;
   	if(me && environment(me) == this_object()) {
   		message_vision("$N�ܿ��ֳ�����һ�����, " , me);
   		switch (random(10)) {
      			case 0:
      			case 1:
      			case 2:
      			case 3:    	message_vision("ȴʲô��û������ ! \n", me);
         					break;
      			case 4:
      			case 5:
      			case 6:    	message_vision("����ʲô��û�������������������� !!  \n", me);
							destruct(bait);				
         					break;
      			case 7:
      			case 8:
      			case 9:		if (!bait->query("fish_bait_zanba")){        
	         					message_vision("ʲô��û������, ���һ��û�� !!  \n", me);
								destruct(bait);				
         						break;
	         				}	
	         			if (REWARD_D->riddle_check(me,"��͵����")==2)	n = 1;
	         				else n = 5;
	         			if (random(n) || !query("scepter")) {      				
	         				message_vision("�㹳�ϵ�����һ�����㣡����  \n", me);
	         				fish = new(__DIR__"obj/fish");
	         				fish->move(me);
         				} else {      
	        				message_vision("��������һ�����ƺ�������ʲô���� ����  \n", me);
         					message_vision("$N�Ѿ��ذ��������������\n",me);
         					fish = new(__DIR__"obj/t_item4");
         					fish->move(me);
         					set("scepter",0);
         				}
         				destruct(bait);
         				break;
      		}
   	}
	return;
}


void 	init(){
	add_action("do_around","around");
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
		|| me->query_temp("zhuanjing/bangpu"))	return 1;
		
	me->add_temp("zhuan_around",1);
	
	if (random (me->query_temp("zhuan_around"))>= 10)
	{
		tell_object(me,WHT"\n����"+ query("short")+"ת����ϣ������ڷ𷨵��˽�������ߡ�\n"NOR);	
		me->delete_temp("zhuan_around");
		me->set_temp("zhuanjing/bangpu",1);
		
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
	
	