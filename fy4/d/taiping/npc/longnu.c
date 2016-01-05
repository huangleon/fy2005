#include <ansi.h>
inherit SMART_NPC;
int helpme();

void create()
{
    	set_name("������Ů",({"naked girl","girl"}));
    	set("long","
�����Ǹ����ӣ�������û�з������죬���ѱ��ݲ��ˡ�������˯�ţ�ֻ��Ϊ��
�ѱ���ĥ��̫�ã��ѿ޵�̫ƣ�롣��ѩ�׵������������϶б����ϣ����Եý�
���������������ˡ�\n");
    	set("gender","Ů��");
    	set("age",12);
    	set("no_arrest",1);
    	set("per",40);
    	set("force",2000);
    	set("max_force",2000);
    	set("combat_exp",500000);  
    	set("attitude", "friendly");
    
	   	set("nb_chat_chance", 100);
	    set("nb_chat_msg_combat", ([
	    		100: (: helpme() :),
		]) ); 
    	
    	set("death_msg",CYN"\n$N��ȻһЦ������Ҳ���ҵĽ��Ѱɡ���\n"NOR);  
    	set("chat_chance",1);
    	set("chat_msg",({
			"������Ů���˸����������Դ���δ�ɵ���ۡ�\n",	
    	}) );
    	setup();    
}


int helpme() {
	object me, longwang, *enemy, player;
	int i,n;
	
	longwang=present("long wang",environment(this_object()));
	if (!longwang) return 1;
	if (longwang->is_fighting()) return 1;
	
	if (query("kee")>=query("max_kee")*4/5)
		message_vision(CYN"$N̾�˿���˵��ԭ����Ҳ�Ǻ�����һ��Ļ��ˡ�\n"NOR,this_object());
	
	enemy=query_enemy();
	n= random(sizeof(enemy));
	player= enemy[n];
	
	if (!player->query_temp("taiping/longwang_kill")) {
		message_vision(CYN"$N��Ц��˵�������ӵ�Ů�ˣ����ֲ����������ְɡ�\n"NOR,longwang);
		for (i=0;i<sizeof(enemy);i++) {
			enemy[i]->kill_ob(longwang);
			longwang->kill_ob(enemy[i]);
		}
		this_object()->remove_all_killer();
	} else 	{
		if (!random(5)) message_vision(WHT"$Nһ�Ĵ���˵�� �ӣ��ͣ�ԭ���ֵ�ϲ�������������\n"NOR,longwang);
	}
	return 1;

}
	
	
void die(){

	object player,longwang;
	int i;
	player=this_object()->query_temp("last_damage_from");
	longwang=present("long wang",environment(this_object()));
	if (player && longwang)
	if (!longwang->is_fighting() && !player->query_temp("taiping/longwang_kill")) {
		message_vision("$N��Ц����ɱ�����ӵ�Ů�ˣ��㻹���ܣ�\n",longwang);	
		player->kill_ob(longwang);
		longwang->kill_ob(player);
	}
	if (longwang) message_vision(CYN"���������˵�ͷ��\n"NOR,this_object());
	::die();
}	