#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "������");
	set("long", @LONG
ʯǽΧ�ɵ�Ժ��ܴ󣬻Һ�ɫ��Ժǽ��ƽ��Ժǽ�����ı�֮�ߣ�����վ�ż���
[33m����[32m��������ؿ����ŷ��ˡ�Ժ��������˾޴��[33mʯ��[32m���в��ٵķ�������æµ��
���ˡ�ǽ��һ��[33m��ˮ��[32m������һ���ʾ�ƣ�[33m�����[32m����Ժ�������ǳ����Ĵ��š�
LONG
	);
    	set("exits", ([ /* sizeof() == 3 */
       		"west" : __DIR__"dayu",
    	]));
    	set("objects", ([

    	]) );
	set("item_desc", ([
	    	"sign": "�����˵ķ��˱��빤���������룩��ʮ�η��ɳ�ȥ��\n",
	    	"��ʾ��" : "�����˵ķ��˱��빤���������룩��ʮ�η��ɳ�ȥ��\n",
	    	"��ˮ��" : "��ˮ���Ｘ����Ӭ���׳����䶯�������źȼ��ڰɣ�drink��\n",
	    	"pond" : "��ˮ���Ｘ����Ӭ���׳����䶯�������źȼ��ڰɣ�drink��\n",	
	    	"����":	  "����˵��������������Խ��ô����������û��������أ�\n",
	    	"ʯ��":	  "����˵��������������Խ��ô����������û��������أ�\n",	
	]) );

//    	set("no_fight", 1);
    	set("no_fly",1);
    	set("outdoors", "jinan");
	set("valid_startroom",1);
	set("coor/x",30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_work", "work");
	add_action("do_drink", "drink");
    	if( interactive(this_player())){
	    	this_player()->set("startroom", __FILE__);
    	}
}


int do_drink(){

	object me= this_player();
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	
	message_vision(CYN"$Nſ�ڳ�ˮ�ӱ߹����غ��˼��ڣ��ȣ����ѵ�Ӣ�۲���ʸ������\n"NOR, me);
	me->perform_busy(1);	
	if (me->query("food")<100) me->set("food",100);
        if (me->query("water")<100) me->set("water",100);	
        return 1;
}

int do_work(){
	object me;
	int i, gin, sen;
	me = this_player();
	i = me->query_temp("jail_work");
	gin = me->query("max_gin")*2/3;
	sen = me->query("max_sen")*2/3;
	if(me->is_busy()) 
		return notify_fail("��Ķ�����û����ɣ����ܹ�����\n");
	message_vision(HIR"$N����ļӹ�ʯ�ϣ����û������ȥ��\n"NOR, me);
	me->receive_damage("gin",gin);
	me->receive_damage("sen",sen);
	me->set_temp("last_damage_from","�ڼ��ϴ���ǿ���Ͷ����������ˡ�\n");
	me->perform_busy(2);
	me->set_temp("jail_work", i+1);
	return 1;	 
}

int valid_leave(object me, string dir){
	object obj;
	
	if(dir == "west" ) {
		if(me->query_temp("jail_work") < 20){
				return notify_fail("����ȵ�����վס����û�����깤�����ߣ���\n");
			} 
			me->delete_temp("jail_work");
			me->set("vendetta/authority", 0);
			me->delete("marks/crime");
			me->set("startroom",AREA_FY"fqkhotel");	
			tell_object(me,HIR"\n����˵����ȥ���ؾ����ˣ����ٷ��¶��ˡ�\n"NOR);	
	}
	return 1;
}
