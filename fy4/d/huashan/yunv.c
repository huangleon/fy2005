#include <ansi.h>
inherit ROOM;
void do_leave();
int poison();
void create()
{
        set("short", "��Ů��");
        set("long", @LONG
һ·�����羰���������ϸ�����ľï�ܣ��������ġ���ʯ�ߣ�СϪ���滨���
�಻֪�������±��س���һ�����������ɹ�࣬����˰����Զ�����⣬��������
��֮�ơ�������һ�Ƿ���̽�����ң��ƿ��еľ�ӥ��͸���ּ��϶�����Կ���һ��
СԺ�������С�
LONG
        );
    set("exits", ([ 
  		"northdown" : __DIR__"canglong",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-12);
	set("coor/y",-58);
	set("coor/z",37);
	setup();
}

void init(){
	object me;
	
	me = this_player();
	if((int)me->query_condition("music") > 0 ) {
		call_out("music_npc", 1, me);
	}
	add_action("do_slide", "slide");
}

int music_npc(object me){
	object obj;
	
	if(!interactive(me) || environment(me) != this_object()){
		return 0;
	}
	if(present("zhen zhen", this_object()) || present("qing qing", this_object())) {
		return 0;
	}

	me->change_condition_duration("music",0);
	
	if (REWARD_D->riddle_check(me,"����ëŮ��") == 3)
	{
		message_vision(HIY"\n������ʱ�򣬺�Ȼ��һ��紵���������з·��и�������Ӱ�ӡ�\n"NOR, me);
		obj = new(__DIR__"npc/qing");
		obj->delete("chat_msg");
		poison();

	}
	else if (REWARD_D->riddle_check(me,"����ëŮ��") == 4 
		|| REWARD_D->riddle_check(me,"����ëŮ��") == 5 
		|| REWARD_D->check_m_success(me,"����ëŮ��"))
	{
		message_vision(HIG"�����Ȼ��ֹ���ڰ��У��ƺ�����̾��һ������\n"NOR, me);
		obj = new(__DIR__"npc/zhenzhen");
	}
	if(objectp(obj))
		obj->move(this_object());
	return 1;

}

int poison(){
	object *inv, *players, me;
	int i;
	inv = all_inventory();
    players = filter_array(inv, (: interactive($1) :));
	for(i=0; i<sizeof(players); i++) {
		if(players[i]->query_condition("music") > 0) {
			players[i]->clear_condition("music");
		} else {
			players[i]->apply_condition("rose_poison", random(10));
    		tell_object(players[i], "�����и���һ�ֵ�����������\n");
    	}
    }   	
}

void go_cliff(object ob){
	object room;
	
	tell_object(ob, YEL"\n�㾪�ȵ��ߵ����ڰ��ߡ�ͻȻ�����ߴ���һ����Ц��һֻ�� 
����һ������Ȼ��������ʯ�ڡ�\n"NOR);
	message("vision", ob->name() + "��Ӱһ�Σ���Ȼ�Ӿ��ڱ���ʧ�ˡ�\n", environment(ob), ob);
	room = find_object(__DIR__"cave1");
	if(!objectp(room)) {
		room = load_object(__DIR__"cave1");
	}	
	ob->move(room);
}

int do_slide(string arg){
	object me, room;
	
	me = this_player();
	if(!me->query("marks/��ɽ�ܶ�")) {
		return 0;
	}
	if(!arg || arg != "rock") {
		return notify_fail("��Ҫ�ƿ�ʲô��\n");
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("������æ��\n");
	}
	tell_object(me, "��������ʯ��������һ�£�����������ܶ���\n");
	message("vision", me->name() + "����Ӱ���±�һ������ʧ�����ˡ�\n", environment(me), me);
	room = find_object(__DIR__"cave1");
	if(!objectp(room)) {
		room = load_object(__DIR__"cave1");
	}
	me->move(room);
	message("vision", "ʯ��ͻȻ���ƿ�һ���죬" + me->name() + "�������˽�����\n", 
			environment(me), me);
	return 1;	
}

void do_leave(){
	object obj, obj2;
	obj = present("hua zhenzhen", this_object());
	obj2 = present("qing qing", this_object());
	if(obj) {	
		message_vision("�ڰ��У�$N����̾��һ��������Ӱһ������ʧ��ҹĻ�С�\n", obj);
		destruct(obj);
	}
	if(obj2) {	
		message_vision("�ڰ��У�$N����̾��һ��������Ӱһ������ʧ��ҹĻ�С�\n", obj2);
		destruct(obj2);
	}	
}

void do_leavee(){
	object obj;
	obj = present("eagle man", this_object());
	if(obj) {
		message_vision("$N����һչ������һֻ��������ʧ���ޱߵĺ�ҹ�С�\n", obj);
		destruct(obj);
	}
}

void do_leaveq(){
	object obj;
	obj = present("qing qing", this_object());
	if(obj) {
		message_vision("$N���Ŀ���$nһ�ۣ�һ�Բ�����ת����ʧ�ںڰ��С� ��\n", obj, this_player());
		destruct(obj);
	}
}	

void wang_you(){
	object stone;
	if(!present("qing shi", this_object()))
	{
		stone = new(__DIR__"obj/stone");
		stone->move(this_object());
	}	
	add_action("do_climb", "climb");
}

int do_climb(string arg){
	object me, qing, stone;
	int i;
	me = this_player();
	i = me->query_temp("marks/qingshi_fall");

	if (REWARD_D->riddle_check(me,"����ëŮ��") != 3)
		return 0;

	if(!arg || (arg != "stone" && arg != "��ʯ" && arg != "qing shi"
				&& arg != "rock" && arg != "ʯ")) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("������æ��\n");
	}
	if(!random(8) 
		&& me->query_skill("move",1)>=150){
		stone = find_object(__DIR__"qingshi");
		message_vision("$N���������˹�����ʯ��\n", me);
		if(!objectp(stone)) {
			stone = load_object(__DIR__"qingshi");
		}
		me->move(stone);
	} else {
		message_vision("�⻬�羵����ʯ�ϻ������֣�$N����������\n", me);
		if (me->query_skill("move",1)< 150)	
			tell_object(me,"�����Ǹ�ʦ��ȥ��ѧ���Ṧ�ɣ�\n");
		me->receive_wound("kee", random(20));
		me->receive_wound("gin", random(20));
		me->receive_wound("sen", random(20));
		me->set_temp("last_damage_from","�ڻ�ɽ����ˤ���ˡ�\n");
		me->set_temp("marks/qingshi_fall", i+1);
	}
	if(i == 4) {
		message_vision("\n$Nһ����һ�ε�����ʯ������$Nһ����һ�ε�ˤ��������ȫ�����÷��ࡣ\n", me);
		if(qing = present("qing qing", this_object())){
			message_vision("\n$N����վ���Ա��ϣ�����$nһ�δε���ȥ����û��ȥ��һ�ѣ�Ҳû����������˼��\n", qing, me);
		}	
	}	 
	return 1;
}

int eagle_come(object me){
	object obj;
	if(!interactive(me) || environment(me) != this_object()) {
		do_leave();
		return 0;
	}
	if(!present("eagle man", this_object())){
		message_vision("\n��Ȼ��һ����Ӱ���ӥһ��Ʈ����¡�������һƬҶ����ƮƮ��������ʯ�ϣ�
�����ǲ�������ô��������ġ�\n", me);
		obj = new(__DIR__"npc/eagleman");
		obj->move(this_object());
		obj->wangyou(me);
	}
}
