inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����Ͽ");
        set("long", @LONG
����Ͽλ����ͭϿ�����Σ�ÿ����ˮ���ڣ�����Ͽ���е�ˮλ�ոߣ�������Ͽ
�Ⱥ󣬺ӹ�ͻȻ���ˮλ����Ȼ�½��������������γ����Ե�ˮλ����С���
������ˮ��֮˵����Ϯ�ഫ�ġ����������š��Ĺ��£�����ָ��Ծ�˴��ĵ�ˮ��˵
����С���㲻η���裬�׷���Ծ���ͨ�������·�ϵ��Źأ��ִ�˵������������
������ģ�����ͬ���е�ٮٮ�ߣ�������������Ĵ�˵���ȵ���ˮ���ڹ�������
����һƬ����أ������������ഹ���ĺõط���
LONG
        );
        set("exits", ([ 
			"east": __DIR__"qingtongxia",
		]));
        set("objects", ([
		]) );
		set("outdoors", "zangbei");
        set("coor/x",-510);
        set("coor/y",550);
        set("coor/z",0);
		set("map","zbeast");
		set("dragon_fish", 2);
		setup();
	
}



void fish_notify(object obj){
   	object me, room, fish, *inv, bait;
	int i;
	
   	me = this_player();
	if (me->is_busy() || me->is_fighting()) {
		tell_object( me, "��������æ�����пյ��㡣\n");
		return ;
	}
	
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

   	if(me && environment(me) == this_object()) {
   		message_vision("$N�ܿ��ֳ�����һ�����, " , me);
   		
   		if ( query("dragon_fish") && bait->query("fish_bait_real") ){        
	    		message_vision("�㹳�ϵ�����һ�������㣡������  \n", me);
	    		add("dragon_fish",-1);
	    		if (query("dragon_fish")<0) set("dragon_fish",0);
	    		fish = new(AREA_TAIPING"obj/dragonfish");
	    		if (fish){
	    			if (!fish->move(me))
	    				fish->move(environment(me));
	    		}
	    		destruct(bait);
        }        
        else {      
	    
   			switch (random(3)) {
      			case 0:    	message_vision("ȴʲô��û������ ! \n", me);
         					break;
      			case 1:    	message_vision("ʲô��û������ , ���ȴ������� !!  \n", me);
							destruct(bait);				
         					break;
      			case 2:		message_vision("�㹳�ϵ���һ������ ����  \n", me);
         					fish = new(AREA_TAIPING"obj/fish");
         					if (fish){
	         					if (!fish->move(me))
	         						fish->move(environment(me));
	         				}
         					destruct(bait);
         					break;
         	}
        }
	}
	return;
}

int	reset(){
	set("dragon_fish",2);
	::reset();
}