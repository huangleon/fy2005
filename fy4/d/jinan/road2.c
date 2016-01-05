// street2.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
string bei();
void do_caolian1(int stage, object me, object obj);
void create()
{
  set("short","б����");
  set("long",@LONG
�ƹ������������������У�����һ������ʯ��·��������ɣ��ʯ�����ѿӿ�
���ݣ����Ծ��������������������ϻ�����Զ�������಻�ϵ�ɽ�ͱ��Ƕ���̩ɽ�ˡ�
·�Եİ��˶�ߵ��Ӳݴ����ƺ���Լ�и�ʯ���� 
LONG
  );
  set("exits",([
         "southwest":__DIR__"road1",
  		"northeast" : __DIR__"road",
               ]));
	set("item_desc", ([
		"shibei" : (: bei :),
		"ʯ��" : (: bei :),
	]));
	set("no_magic", 1);
	set("cleaned", 0);
    set("outdoors", "jinan");
	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_kill", "kill");
}
int do_kill(string arg){
	object me;
	me = this_player();
	message_vision("��е�һ��ǿ�ҵ�ɱ�����Բݴ�֮�У����ɵ�ȡ����ɱ�˵���ͷ��\n", me);	
	return 1;
}

string bei(){
	object me;
	me = this_player();
	if(!query("cleaned")) {
		tell_object(me, "��·��ǿ鳯͢������ʯ��, �ƺ��Ѿ����������տ���������ߵ��Ӳݸ�\n");
		tell_object(me, "���˱��棬���޷���������д��ʲô�����ƺ���������һ�£��������\n");
		add_action("do_clean", "clean");
	} else {
		tell_object(me, "ʯ���Ͽ���\n\n"); 
		tell_object(me, RED"����ȫ������ʥ������������Т�ʵ��������꣬����ͬ����·������ʹ\n"NOR);
		tell_object(me, RED"���ɴ��ƽ���ڴˡ� \n\n"NOR);
		tell_object(me, HIR"�������ݸ���\n"NOR); 
          if(me->query("class") == "official" 
          		&& REWARD_D->riddle_check(me,"�ݺ�����")==1){
       //   		&& me->query("marks/���������ݺ�����") == 1){
			tell_object(me, "\n��������㲻���������������³۳ҽ��������¡�\n");
			message("vision", me->name()+"������ǰ��ʯ���ƺ������˳�˼��\n", environment(me), me);
			add_action("do_caolian", "caolian");
			me->start_busy(2);
			call_out("do_spear", 3, me);
		}
	}
	return "";
}
void do_spear(object me){
	if(environment(me) != this_object()) {
		return;
	} 
	if(me->query_skill("yue-spear",1) >= 120){	
		tell_object(me, CYN"��Ȼ���ѣ������ие�һ�ɶ����̲�ס�����һ��������ƽǹ�������������\n"NOR); 
		me->set_temp("marks/caolian_yue", 1);
	} else {
		message_vision("$N��̾��һ������ ��ʯ��ǰ����һ�ϡ�\n", me);
	}
}

int do_caolian(){
	object obj, me;
	me = this_player();
	if(!me->query_temp("marks/caolian_yue")) {
		return 0;
	}
	obj = me->query_temp("weapon");
	if(!obj){
		return notify_fail("�����в�û�г�ǹ����ô����?\n");
	}
	if(obj->query("flag") == 25) {
		message_vision(HIC"$N����������������ͷ��ʰ��ɽ�ӣ������ڡ���������" + obj->name() +"��ת��\n"NOR, me);
		message_vision(HIC"ǹ���������ϣ�ֱ��ǰ��ȥ��\n"NOR, me); 
		me->start_busy(2);
		call_out("do_caolian1", 2, 1, me, obj);
	}else {
		tell_object(me, "�����в�û�г�ǹ����ô����?\n");
	}
	return 1;
}

void do_caolian1(int stage, object me, object obj){
	if(environment(me) != this_object()){
		return;
	}
	if(stage == 1){
		message_vision(HIC"$N��̾�����������ܣ���δѩ�����Ӻޣ���ʱ�𣡡�������" + obj->name() + "�γ�����ǹӰ��\n"NOR, me);
		me->start_busy(2);
		call_out("do_caolian1", 2, 2, me, obj);
	} else if(stage == 2){
		message_vision(HIC"$N�����ɫ������������ʮ��������������ǹ��ͻת��������ɨ��\n"NOR, me);
		me->start_busy(2);
		call_out("do_caolian1", 2, 3, me, obj);
	} else if(stage == 3){
		message_vision(HIC"$Nһ����Х�����ݳ�����̤�ƺ���ɽȱ��������̤����ǰ����������"
				+obj->name() + "ƽƽ�ݳ�������������\n"NOR, me);
		me->start_busy(2);
		call_out("do_caolian1", 2, 4, me, obj);
	} else if(stage == 4){
		message_vision(HIC"$N��ͷ��Ŷ������ǧ��·�ƺ��¡�������" + obj->name() + "�����㣬��ؽ�������\n"NOR, me);
		message_vision(HIC"ɨ��һ��ǹӰ��\n"NOR, me);
		me->start_busy(2);
		call_out("do_caolian1", 2, 5, me, obj);
	} else if(stage == 5){
		message_vision(HIY"\n$N���������е�" + obj->name() + ", ���˲���ͷ�ĺ�ˮ�� ��ʯ��ǰ����һ�ϡ�\n"NOR, me);
		tell_object(me, "�������ƺ�����һ˿�����޷������\n");
		REWARD_D->riddle_set(me,"�ݺ�����",2);
//		me->set("marks/����������ƽǹ��", 1); 
	}
}

int do_clean(){
	object me, obj;
	me = this_player();
	obj = me->query_temp("weapon");
	if( !obj ) {
            return notify_fail("������֣���ô��������͵Ĳݣ�\n");
	}
	if( obj->query("flag") == 4){
		message_vision("$N�����е�" + obj->name() + "�����ظ�ȥ��ʯ��ǰ����Ӳݡ�\n", me);
		tell_object(me, "ʯ���ϵ��ּ�������¶������\n");
		me->start_busy(3);
		set("cleaned", 1);
		remove_action("do_clean", "clean");
	} else {
		tell_object(me, "��������ݵĶ������԰ɣ�\n");
	}	
	return 1;
}

void reset(){
	::reset();
	set("cleaned", 0);
}
