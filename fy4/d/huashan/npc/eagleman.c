#include <ansi.h>
inherit NPC;
int wandao(object me);
int do_killqing(object me);
void create()
{
	set_name("��ӥ����", ({ "eagle man"}) );
	set("gender", "����" );
	set("age", 55);
	
	set("long", @LONG
�����ֻ�����߶�ߣ����߳��Ľ����Ӵ��������ϣ��Ѿ������˵ء����ĺ� 
�ӱ�������Ӹ������ƽ����ɵĽ��Ⱥ��ӻ����� 
LONG
);
    
    	set("combat_exp", 10000000);
	set("attitude", "friendly");
	set("inquiry_wangyou", 0);
	
	set_skill("dodge", 250);
	set_skill("move", 200);
	set_skill("parry", 250);
	set_skill("sword", 200);
	set_skill("doomsword", 200);
	set_skill("doomsteps", 200);
	set_skill("unarmed",200);
	set_skill("doomstrike",200);
	map_skill("unarmed","doomstrike");
	map_skill("sword", "doomsword");
	map_skill("parry", "doomsword");
	map_skill("move", "doomsteps");
	map_skill("dodge", "doomsteps");
	
	set("str", 80);
	set("require_rescue", 0);
	set("reset", 1);
	setup();
	carry_object("/obj/armor/cloth",
		([ 	"name" : HIY"������"NOR,
			"long" : "һ�����߳��ý�˿֯�ɵ�����",
			"value": 10000,
			"weight": 3000]) 
		 )->wear();
}


int wangyou(object me){
	object obj;
	if(interactive(me) && environment(me) == environment(this_object())) {
		message_vision("\n$N����ؿ���$nһ�ۣ����������ķ����ǲ���õ����ǲݵģ���ֻ�ܸ���������ա���\n",
				this_object(), me); 
			message_vision("$N���ŵ������㻹�ǰ��������Ұɡ����������������󣯣�\n", this_object());
		add_action("do_accept", "accept");
		set("inquiry_wangyou", 1);
		call_out("remove_inquiry", 15, me);
		add_action("do_rescue", "rescue");
	} else {
		environment(this_object())->do_leavee();
		environment(this_object())->do_leave();
	}
}

int remove_inquiry(object me){
	object obj;
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
	}
	obj = present("qing qing", environment(this_object()));
	if(objectp(obj)){
		message_vision("$N��Ц��������Ȼ���᲻��...����$N���۹�Ʈ�����ࡣ\n", this_object());
	}
	set("inquiry_wangyou", 0);
	wandao(me);
}


int do_accept(string arg){
	object me, grass;
	me = this_player();
	remove_call_out("remove_inquiry");
	if(!arg || (arg != "yes" && arg != "no")) {
		return 0;
	}
	if(!query("inquiry_wangyou")) {
		return 0;
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("������æ��\n");
	}
	grass = present("wang you", me);
	if(!objectp(grass)) {
		message_vision("$N��Цһ��������ƭ�ң���\n", this_object());
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		return 0;
	}
	if(arg == "yes") 
	{
		set("inquiry_wangyou", 0);
		message_vision(BLU"$N����$n�����ƣ��������ջ󣬰����ǲݽ���$n��\n"NOR, me, this_object());  
     		message_vision("$N������Ц���ӹ����ǲݡ�\n", this_object()); 
        	destruct(grass);

		environment(this_object())->do_leaveq();
		environment(this_object())->do_leavee();
		
	}
	if(arg == "no") {
		set("inquiry_wangyou", 0);
		message_vision(YEL"$Nֱ�����˵�Ŀ�⣺�����ǲ�����Ϊ�������ժ�ģ���ָ�����ȣ���ժȡ�ں�\n"NOR, me);
     		message_vision(YEL"���ǰ�����ã��β��Լ����֣���\n"NOR, me);
     		message_vision(HIY"\n$N����һ������Ҫ�Ҷ��֣��㻹���䣡��\n"NOR, this_object()); 

//     	call_out("wandao", 3, me); 
		wandao(me);
	}	
	return 1;
}

int wandao(object me){
	object obj, grass;
	if(obj = present("qing qing", environment(this_object()))) {
		message_vision("\n$N�������������ϵ��Ǳ������Ǳ�����ġ�����ĵ���\n", this_object());
		message_vision(HIW"$N���䵶��Բ�������������⡣\n"NOR, obj);
 		obj->xiaolou(me);
	} else {
		grass = present("wang you", me);
		if(objectp(grass)){
			message_vision("\n$Nֻ������ǰ��Ӱһ����$n������Ȼ����һ����̵�С�ݡ�\n", me, this_object());
			destruct(grass);
		}
		environment(this_object())->do_leavee();
	}
	return 1;
}


int wf(object me) {
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
	} else {
		call_out("wandao_found", 2, me);
	}
	return 1;
}

int wandao_found(object me){
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
	}	
//	message_vision("\n$N��Ȼ�����Ц����Ц������Ȼ����ѵ����������ۣ���������ҵ�����ѵ�����\n", 
//			this_object());
//	message_vision("\n��Ц���У����ѳ��ʡ�\n", this_object()); 
	message_vision(HIY"\n$NͻȻ�������������綼û�����������˿죡\n"NOR,
			this_object());
	message_vision(HIR"����һ����������˾͵�������������һ���ʻ���Ȼ��ή��׹���˻��١�\n"NOR, this_object()); 
	message_vision(RED"\n$N���ӥ��һ���»�����һ��������������һ����׼ȷ���ݶ���Ѹ�٣����顣\n"NOR,
			this_object()); 
	tell_object(me, "���໺�����£�����������������۾�������ȥ���ƺ��Ѿ�ʧȥ�˵ֿ���������
���������塡����磩\n");
//	tell_object(me, "\n���ʧɫ�������ȥ���������������塡��������磩\n"); 
	me->set_temp("rescue_time", time());
// 	add_action("do_rescue", "rescue");	
	set("require_rescue", 1);
	call_out("do_killqing", 15, me);
	return 1;
}

int do_rescue(string arg){
	object me, obj;
	int i;
	me = this_player();
	if(!interactive(me) || environment(me) != environment(this_object())) {
		environment(this_object())->do_leave();
		environment(this_object())->do_leavee();
		return 1;
	}
	if(!obj = present("qing qing", environment(this_object()))) {
		environment(this_object())->do_leavee();
		return 1;
	}	
	if(!query("require_rescue")) {
		return 0;
	}
	if(!arg || arg != "qing") {
		return notify_fail("��Ҫ��˭��\n");
	} else {
		remove_call_out("do_killqing");
		if(time() - (int)me->query_temp("rescue_time") < 10) {
			message_vision("\n������һ�����䣬$N��Ȼ�˹�ȥ��������������ϡ�����һ����������$N�ı���\n", me);
			tell_object(me, WHT"\n�㲢������ʹ�ࡣ��ֻ���ú��䣬ֻ�������ֲ��ɿ��ܵĺ��⣬��Ȼ��������ı���
������衣\n"NOR); 
			obj->do_killeagle(me);

		} else {
			tell_object(me, "����ԥһ�£������Ǹ�İ����Ů�ӣ��������˾����Ǹ�ɱ��ֵ��ð����֮����\n");
			tell_object(me, "��ͻ������һ��������ӥ���˽������ˡ�\n");
			message("vision", "          ����ɨ��\n", environment(me), me);
			me->unconcious();  
			do_killqing(me);
		}
	}
	return 1;
}

int do_killqing(object me){
	object obj, blade;
	obj = present("qing qing", environment(this_object()));
	if(objectp(obj)) {
		message_vision("\n����û��$N����ǰ���㽫��Ҳ����������������������۲��ˡ�\n", obj);
		blade = present("moonblade", obj);
		message_vision("�����û�п���$N�Ķ�������֪�����䵶ȴ������$P���С�\n", this_object());
		message_vision(HIW"��ɫ�ĵ������¹������Ŵ��۵Ĺ⣬�ƺ��ڳ�Ц����������硣\n"NOR,
				this_object());
		destruct(blade);
		obj->die();
		environment(this_object())->do_leavee();
	} else {
		environment(this_object())->do_leavee();
	}
	return 1;
}

