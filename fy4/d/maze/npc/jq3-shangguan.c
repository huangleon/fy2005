inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name("�Ϲٽ��", ({ "shangguan jinhong","shangguan"}) );
    	set("nickname", RED"����˫��"NOR);
    	set("gender", "����" );
    	set("class", "assassin");
    	set("long","
һ������վ������ǰ�����ţ���ʱ������ھ����Ϲ��������ģ�����ż����¶��
һ˿�����Ц�ݡ�����վ�ŵġ�����Ϊһ����ֻҪ���������ͻ����Լ��ľ�����
�ڣ�һ���˵ľ������ɳڣ���������ɴ���\n");

       	set("age", 44);
    	set("attitude","aggressive");

	set("zombie-killer",1);
	set_temp("apply/haste",300);
    	set("combat_exp", 8000000);
    	
    	set("officer-killer",1);		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
    	    
	auto_npc_setup("liaoyin",350,220,0,"/obj/weapon/","fighter_w","longfenghuan1",2);
	setup();
	
    	carry_object(AREA_FY"npc/obj/yellow_suit")->wear();
    	carry_object(AREA_FY"npc/obj/hat")->wear();
    	carry_object(AREA_FY"npc/obj/longfenghuan")->wield();
}

void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	object *inv, lin;
	string my_position;
	if( !ob || environment(ob) != environment()) return;
	message_vision("
�Ϲٽ��ĮȻ������ͻȻȼ�������΢΢Ц�����������������ϵ������ˣ�
�������� ���ﻷ�Դ���������ͷ����Ѫ���Ѿ��ܾ�û��Ѫ��ι�����ˡ�\n"NOR,ob);
}

void	die(){
	object cloth;
	object me, owner;
	object *inv;
	int i;
	
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if (!query("reincar")) {
        	message_vision(CYN"
�����������Ц�������˲�����õ��������Ϲ٣������ˣ������£��������
��Ů�ˣ���ȫ�������ˡ� 

�����������㣬���������ž��ž�������������Ϲٵ�����Ǻ��Ŀڴ��� 
���𡣡������������������дʡ� 

�������Ϲٽ�罩ֱ��ͻȻ���������� \n\n"NOR + HIR"

�Ϲٽ�����Ѫ���˫���������������Ƹ�ʢ��\n\n"NOR, this_object());
		set("combat_exp",12000000);
		set("reincar",1);
		set("kee",query("max_kee"));
		set("gin",query("max_gin"));
		set("sen",query("max_sen"));
		set("eff_kee",query("max_kee"));
		set("eff_gin",query("max_gin"));
		set("eff_sen",query("max_sen"));
		set("resistance/gin",50);
		set("resistance/sen",50);
		set("resistance/kee",50);
		
		set("title",HIR"������"NOR);
		inv = all_inventory(environment());
		for (i=0;i<sizeof(inv);i++)
		{
			if (userp(inv[i])) kill_ob(inv[i]);	
		}
		return ;
	}
	if (me)
	if (present("meihuadao", environment()) && present("chi xu",environment()) )
		environment()->event1(me,0);
	
	// ����Ӧ�����Ϲٵ�һЩ�ö����ˡ����������д����롣
	::die();
}

void 	unconcious(){
	die();
}
