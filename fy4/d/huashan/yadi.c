#include <ansi.h>
inherit ROOM;
string flower();
string deadwolf();

void create()
{
        set("short", "ɽ�µ�");
        set("long", @LONG
ɽ�£����������������Ұ���Ӱ�ӡ��쳣�İ������㲻����������߶Ƚ��ţ�
�������²�֪���ж����˺�Ұ����������ˣ��Ĵ������˰׹ǣ��׹Ƕ��У�������
һЩ�Ӳݣ���Щ�����������޵Ļ��䡣
LONG
        );
	set("item_desc", ([
		"cliff" : "ɽ����Ȼ���ͣ�ȴ�����˳��٣������������������⣩��\n",
		"ɽ��" : "ɽ����Ȼ���ͣ�ȴ�����˳��٣������������������⣩��\n",	
		"grass" : (: flower :),
		"�Ӳ�" : (: flower :),
		"flower": (: flower :),
		"����":   (: flower :),
		"�׹�": (: deadwolf :),
		"skeletons": (: deadwolf :),
		"skeleton": (: deadwolf :),
	]));
    	set("flower_amount", 3);
    	set("jade_bottle", 1);
    	set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",-40);
	set("coor/z",-45);
	setup();

}

void init(){
	add_action("do_climb", "climb");
	add_action("do_pick", "pick");
	add_action("do_search", "search");
}

string flower(){
	object me;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 2 && query("flower_amount") > 0) {
		tell_object(me, "�׹Ƕ���Ӳݴ��п���һ���ʺ��С�����Ե���ô��Ŀ���ģ�����롡�������򣩡�\n");
	} else if(i == 4){
		tell_object(me, "��ѩ��������Ȼ�м���׹Ǽ���ɫ���Ӳ�¶����\n");	
	} else {
		tell_object(me, "�׹Ƕ������м��Դ������ε��Ӳݡ�\n");
	}
	return "";	
}

string deadwolf()
{
	object me,obj;
	me = this_player();
	tell_object(me,HIW"һ��ɢ�ҵİ׹ǣ�Ҳ��֪�������ޣ���Ŀֻ��һƬ���۵İס�\n"NOR);
	if( me->query_temp("followcrow")) 
	{
		if (present("deadwolf",me))
		{
			return "";
		}
		tell_object(me,"һ��Ƥ�����ã��ԿǱ���������ɭɭ�׹�����Ϊ���ġ�\n");
		if (!obj = present("deadwolf",this_object()))
		{
			obj = new(__DIR__"obj/deadwolf");
			obj ->move(this_object());
			me->delete_temp("followcrow");
		}
	}
	return "";
}

int do_search(){
	object me, obj;
	int i,j;
	
	me = this_player();
	i = NATURE_D->get_season();
		
	message_vision("$N�ڰ׹Ƕ��é�ݴ�����ϸ��Ѱ��\n", me);
	if(i != 4 )
		return notify_fail("é�ݳ��������дУ���ʲôҲû���ҵ���\n");
	
	j = me->query_kar();
	if(random(j) > 20 && query("jade_bottle")){
		message_vision("$N����������һ�£���������Ѫ����\n",me);
		me->receive_wound("kee",200);
		me->set_temp("last_damage_from","�����Ҷ��������������ˡ�\n");
		tell_object(me, "�㷢����һ��СС����ƿ��\n");
		obj = new(__DIR__"obj/bottle");
		if(objectp(obj)){
			obj->move(me);
		}
		add("jade_bottle", -1);
	} else {
		tell_object(me, "��ʲôҲû�з��֡�\n");
	}
	return 1;
}

void reset(){
	::reset();
	if (!random(4))	set("flower_amount", 1);
	if (!random(5))	set("jade_bottle", 1);
}

int do_pick(string arg){
	object me, flower;
	int i;
	
	me = this_player();
	if(!arg || (arg != "flower" && arg != "��")){
		return 0;
	}
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("������æ��\n");
	}
	i = NATURE_D->get_season();
	if(i != 2 )
		return notify_fail("���ڲ��ԣ�û�л�Ү��\n");
		
	if(query("flower_amount") == 0) {
		return notify_fail("�Ѿ�û�л��ˡ�\n");
	}
	message_vision("$N�ߵ��׹Ǵ��У�����ժ����һ���ʺ�ɫ��С����\n", me);
	message_vision("$NͻȻ��������һ�£���������Ѫ����\n",me);
	me->receive_wound("kee",200);
	me->set_temp("last_damage_from","�����黨֮�̶�����\n");
	flower = new(__DIR__"obj/redflower");
	if(objectp(flower)){
		flower->move(me);
	}
	add("flower_amount", -1);
	return 1;
}


int do_climb(string arg){ 
	object me, room;
	
	me = this_player();
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("������æ��\n");
	}
	if(!arg || (arg != "cliff" && arg != "ɽ��" && arg!="up")) {
		return 0;
	}
	message_vision("$N�ֽ����ã���ץ�����������±ڣ�����������ȥ��\n", me);
	me->start_busy(2);
	call_out("fall", 2, me);
	return 1;
}


void fall(object me){
	object room;
	int j;
	if (me->is_ghost() || !me) 	return;	
	j = me->query_skill("move",1);
	if(j+1 <random(40)) {
		tell_object(me, "�����һ��������������ȥ��ֱˤ���߻���ء�\n");
		message("vision", me->name()+ "����һ�����ȣ����±��ϵ�����������\n", environment(me), me);
				me->receive_wound("kee", random(50));
	    		me->receive_wound("gin", random(50));
            	me->receive_wound("sen", random(50));
            	me->set_temp("last_damage_from","��ɽ����ˤ����ˤ���ˡ�\n");
	} else {
		message("vision", me->name() + "Խ��Խ�����ڷ�����ɽ�¡�\n", environment(me), me);
		room = find_object(__DIR__"duanshan");
		if(!objectp(room)){
			room = load_object(__DIR__"duanshan");
		}		
		me->move(room);
		message_vision("$N˫������һ�ţ�����Խ����ɽ�¡�\n", me);
	}	
	
}

