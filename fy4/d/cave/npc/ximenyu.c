#include <ansi.h>
inherit NPC;

void create()
{
    set_name("������", ({"ximen yu","ximen"}) );
        set("gender", "����" );
        set("nickname", HIC"����ʮ��"NOR);
        set("title", "������ �ֶ����");
        set("long", "
һ�ź�˹�ģ��ܺ������װ׾����������������εøɾ������롣������
˫�֣�ʩʩȻ�����ŷ���������������΢Ц���۾�Ҳ��Ц���еء�����
�������Ǹ��ص����ݷ����ѵ���š�\n");
 	set("attitude", "friendly");
 	set("class","beggar");
 	set("age", 45);
  	
    	set("reward_npc", 1);
        set("difficulty", 5);
    	
    	set("combat_exp", 4000000);

       	set_skill("unarmed", 200);
        set_skill("dragonstrike",180);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("five-steps",180);
        
        map_skill("dodge","five-steps");
        map_skill("unarmed","dragonstrike");
        map_skill("move","five-steps");
       
        set("no_busy",4);

        set("chat_chance", 1);
        set("chat_msg", ({
        "������������Ѫ���еĸ�����˫˫����Ц����˭���������ᣬ������³����ٺ١�\n",
		"��������Ц������������Ԫ�գ��عٽ��£����˼��ƶ񣬵�ʿ��������\n����������ͽ����ý��ѡ�\n",
        }) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/stone_5");

}

void killed(object me){
	message_vision("$N�������Ű����Ŵ����������ǹ���૵�����ô���ܡ�����ô���ܣ������� 
����������û��һ�㡣�����ĺ������ˡ����������С���\n", this_object()); 
	call_out("dead", 3, me);
	return;
}

void dead(object me){
	object gao;
	if(present("gao li", environment()) && present("shuang shuang", environment())){
		gao = present("gao li", environment());
		this_object()->set_temp("last_damage_from",gao);	
		gao->do_leave(me);
	}
	this_object()->die();
}

void die(){
	object *inv, ob, killer;
	int i;
	if(objectp(killer=query_temp("last_damage_from") ))
	if (killer->query("combat_exp")<4000000) {
		::die();
		return;
		}
	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++){
		ob = inv[i];
		if(ob->query("name")== HIM"��ˮ��"NOR) {
			destruct(ob);
		}
	}
	::die();
}