#include <ansi.h>
inherit ROOM;
string staff();
void create(){
    set("short", "����ؿ�");
	set("long", @LONG
��������ɫ������ļȻ��䣬ɲ�Ǽ�Ũ�Ʒ���������������������������ɭ
�޹������Ȼ��ʮһ���С��һ�ľ������ĸߴ�ٳߣ���ΰ�������ж�����
��֮�����������֮�ƣ���Ȼ���ϹŴ�˵�Ĵ�����ȣ�����ʮ�����񣬷ֱ�Ϊ����
�ġ��֡��ҡ��ڡ��ݡ�а���ޡ������ͳ��ĸ��������죬�ܹ����ӣ������Զ��
ÿ�����������ȶ���Ĥ�ݡ�������ɽ��Ұ����ɭɭ�׹ǣ����е������쳣��ͷ��
��Ⱦ�����Ĥ�ݡ�
LONG);
	set("staff", 1);
	set("type","street");
	set("exits",([
        "north":__DIR__"chiyoudao2",
	]) );
    set("objects",([
    ]) ); 
    set("item_desc", ([
            "����": (: staff :),
            "staff": (: staff :),
    ]) );
	setup();
}

/*
void init(){
	add_action("do_pull", "pull");
}

string staff(){
	object me;
	me = this_player();
	if(query("staff")){
		tell_object(me, YEL"\n
һ������������ľ�Ƴɵķ��ȣ�һ��������������Ⱦ���ͷ������¶����һ����
���ɹ⻪��Ŀ����֪���Ƿ��ܰγ�����pull)���ݴ��Ϲ�ʱ�Ƶ�նɱ��Ⱦ��׺�
Ψ�������겻ɢ�����������������������Ȳ������ʯ������ס�ⲻ��֮�ף�
�������÷���\n\n"NOR);
	} else {
		tell_object(me, "���������ͷ���ķ�����Ȼ������ֻʣһ���ն���\n");
	}
	return "";
}


int do_pull(string arg){
	object me, staff;
	int damage;
	me = this_player();
	if(!arg || (arg != "staff" && arg != "����")) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if(!query("staff")) {
		return notify_fail("�Ѿ�û�з����ˡ�\n");
	}
	if(me->query("kee") < 100) {
		return notify_fail("��û���㹻����Ѫ��\n");
	}
	if(me->query("force_factor") > 80 && me->query_str() > 30 ) {
		message_vision("$N˫�ֽ�����ס���ᷨ�ȣ�����һҧ��������Ѫ���䣬ŭ��һ�����𣡣�\n", me);
		message_vision(HIY"\n���ᷨ��ͻȻ�ų�����𻪣���ɫ���Σ�ɽҡ�ض�֮�䣬����Ӧ�����𣬳��������\n"NOR,
				me);  
		set("long", @LONG
��������ɫ������ļ����䣬ɲ�Ǽ�Ũ�Ʒ���������������������������ɭ
�޹������Ȼ��ʮһ���С��һ�ľ������ľ���ߴ�ٳߣ���ΰ�������ж�
������֮�����������֮�ƣ���Ȼ�����ϹŴ�˵�Ĵ�����ȣ�����ʮ�����񣬷ֱ�
Ϊ�����ġ��֡��ҡ��ڡ��ݡ�а���ޡ������ͳ��ĸ��������죬�ܹ����ӣ���
���������Զ�����������Ĥ�ݡ�����������ɽ��Ұ����ɭɭ�׹ǣ������е���
���쳣����ÿһ�߰׹Ǿ�ͷ����Ⱦ��񣬾�����Ĥ�ݡ�
LONG
);
		set("staff", 0);
		me->start_busy(4);
		me->set_temp("marks/chiyou", 1);
		call_out("stone_fall", 3, me);
	} else {
		message_vision("$N˫�ֽ�����ס���ᷨ�ȣ�����һҧ��������Ѫ���䣬ŭ��һ�����𣡣�\n", me);
		message_vision("���ᷨ����˿������\n", me);
		me->start_busy(4);
		damage = me->query("kee") / 5;
		me->receive_damage("kee", damage);
	}

	return 1;
}

void stone_fall(object me){
	object *all, *inv, room, obj;
	int i;
	string *names = ({"chiyoudao", "chiyoudao1", "chiyoudao2", "chiyoudao3", "chiyoudao4", "chiyoudao5",
			"chiyoudao6", "chiyoudao7", "chiyoudao8", "chiyoudao9"});
	
	all = all_inventory();
	message_vision("\nͻȻ֮������ؿ�����������Ѱ㣬Ũ�Ʒ���������������ɽʯ���缲�籩���\n", me);	 
	message_vision("�������£�\n", me); 
	message_vision("\n$N��ɫ��䣬����ȫ������ʯ�籩�п��Ѱ��һ��������\n", me);
	for(i=0;i<sizeof(names);i++){
		if( obj = find_object(__DIR__+names[i])) {
		tell_object(obj,HIY "\n\nԶ������һ��¡¡���죬����������ʯ��������������\n\n"NOR);
		}
	}
	inv = filter_array(all, (: interactive($1) && !$1->query_temp("marks/chiyou") :));
	for(i=0; i<sizeof(inv); i++) {
		message_vision(HIY"$N����ͻ�������ı仯����Ŀ�ɿڴ���ֻ��������ʯ�ݺݵ����˹�����\n"NOR, inv[i]);
		message_vision(HIY"�����ǵ��޿ɵ����޿ɶ㡣\n"NOR, inv[i]);
		if(inv[i]->query_skill("dodge",1)>=150 && inv[i]->query_skill("parry",1)>=150){
			message_vision(HIG"\n����䲻�ݷ��������$N����˾�ʯ�Ĺ�����\n"NOR, inv[i]);
		} else {
			tell_object(inv[i], "�����Ҷ���ǰ�������������ʯ��Ϯ����\n");
			me->start_busy(3);
			room = find_object(__DIR__"chiyoudao");
			if(!objectp(room)){
				room = load_object(__DIR__"chiyoudao");
			}
			inv[i]->move(room);		
			message_vision(RED"\n$Nһ������������������ʯ�ݺݵ����˹���������\n"NOR, inv[i]); 
			inv[i]->unconcious();
		}
	}
	if(me->query_skill("dodge",1) >= 150 && me->query_skill("parry",1) >= 150 && random(100)){
		remove_call_out("chiyou");
		call_out("chiyou", 3, me);
	} else {
		tell_object(me, "�����Ҷ���ǰ�������������ʯ��Ϯ����\n\n");
		me->start_busy(3);
		room = find_object(__DIR__"chiyoudao");
		if(!objectp(room)){
			room = load_object(__DIR__"chiyoudao");
		}
		me->move(room);
		message_vision(RED"$Nһ������������������ʯ�ݺݵ����˹���������\n"NOR, me); 
		if(!random(200)){
			me->die();
		} else {
			me->unconcious();
		}
	}
}

void chiyou(object ob){
	object chiyou;
	if(!interactive(ob) && environment(ob) != this_object()){
		return;
	}
	message_vision(HIB"\n������ʯ�У����է����ɫ���һƬ�������·���������Ұ��������ŭ��\n"NOR, ob);
	message_vision(HIR"\n�ʺ���Ѫ��Ĵ������ȼ��һƬ��������һ���ߴ�ٳߣ����������ľ޺���\n"NOR,ob); 
	message_vision(HIR"Զ����������������ÿһ���ط�����������а������Ĥ�ݣ��������\n\n"NOR, ob);
	message_vision(HIY"              ������������ս���񣭣�򿣭�ȣ��أ�������  \n\n"NOR, ob);
	chiyou = new(__DIR__"npc/chiyou");
	if(objectp(chiyou) && !present("chi you", this_object())){
		chiyou->move(this_object());
		chiyou->set("time",time());
	}else
		destruct(chiyou);
	chiyou->chiyou_call(ob); 	
}

//	Notice: part of the room reset is in /d/wolfmount/cliffroad3.

void reset(){
	object ob;
	::reset();
	if (ob=present("chi you",this_object())) 
	if (!ob->is_fighting()) {
		message_vision(CYN"\n����ͻȻ�ѿ������죬$N���Ӵ���������������ֻ�������Ŀ�Ц���ص���ֹ��\n"NOR, ob);
		destruct(ob);
	}	
	
}

*/

int valid_leave(object obj, string dir){
	object ob;
	if(dir == "north" && (ob=(present("chi you", this_object())))){
		if (!ob->query("staff"))
			return notify_fail("������Ӵ��������ס�˶��ڡ�\n");
	} 
	return ::valid_leave(obj, dir);
}
