// Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ɳ");
	set("long", @LONG
���Ѿ�������ɳ֮�У�����û��һ�������ĵط�����һ����������ȥ������
������(pull)��һ�ѣ�������뿪������±ȵ��컹�ѡ����ƺ��Ѿ������ڰ��޳�
���������֡�
LONG
	);

    set("NONPC",1);
	set("coor/x",-1060);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}

void init(){	
	
	object ob;
	if( interactive( ob = this_player())) {
		ob->set_temp("sinking", 1);
		remove_call_out("sinking");
		call_out("sinking", 1, ob);
	}
}

int sinking(object ob){
	int i, j;
	int damage;
  
    	if(ob && environment(ob) == this_object()){
		j = ob->query_temp("sinking");
		message_vision(HIW"$N������ɳ��������һЩ����", ob);
		message_vision("$N�����ھ����п��˳�������\n"NOR, ob);
		ob->set_temp("sinking", j + 1);
		damage = random(5)+5;
		i =  (int)ob->query("kee");
		ob->set("kee",(int) i - damage);
		if (j == 5) {
			message_vision(HIG"\nͻȻ�䣬��ɳ�»������ƶ���һ�¡�¶����һ�����µĶ��ڡ�\n"NOR,ob);
			set("exits/down", __DIR__"chensha1");
            		call_out("close_path", random(6)+10, ob);
		}
		if( environment(ob) == this_object()){
			call_out("sinking",random(5)+10, ob);	
		}
	}
	else

	return 1;
}

int close_path(object ob){
	if( query("exits/down") ) {
    	message("vision","\n��ɳ�����»�������Խ��ԽС���ܿ�Ͳ����ˡ�\n", this_object() );
    	delete("exits/down");
    }
}


int valid_leave(object who,string dir)
{
    	object me;
     
    	me = this_player();
    	if(dir=="down"){
		if(me->query_cps() > 20) {
    		message("vision",me->name() + "һ���ģ���������������ȥ... " , this_object(), me);
        	return 1;
        } else {
        	return notify_fail("�����ƺ�����ף���������ԥ��������������ɳ�����ꡣ \n");
    	}
    }
    return 0;
}

void reset(){
	object *inv;
	int num,i;	
	::reset();
	inv = all_inventory();
	for (i=0;i<sizeof(inv);i++){
		if (userp(inv[i])) {
			message_vision(HIW"��Ѱ���þ�ȫ����������$N����ɳ�о��˳�����\n"NOR, inv[i]);
			sscanf(file_name(this_object()),__DIR__"quiclsamd%d",num);
        	inv[i]->move(__DIR__"desert"+num);
        	tell_object(inv[i],CYN"\n��Ѱ����������Դ����Ժ�С������˵�ձ���ʧ�ˣ�\n\n"NOR);
		}
	}
}	