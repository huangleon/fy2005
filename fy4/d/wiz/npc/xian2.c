inherit NPC;
#include <ansi.h>
void create()
{
	object armor;
	set_name("ƽ������", ({ "shang ren","ren"}) );
	set("gender", "����" );
	set("title",HIW"��������"NOR);
	set("nickname",HIR"��ꫵ���"NOR);
	set("age", 370+random(10));
	set("class","lama");        
	set("long","һ����ò�췲����ɮ �����ߺ�����棬Ц�ݿ��ͣ����׼��׷ױ���׻�ɫ��\n");
	set("class","shaolin");
        set("combat_exp", 10000000);
        set("score", random(90000));
        set("reward_npc", 1);
	set("difficulty",5);
	
	set_skill("perception",200);
	set_skill("iron-cloth", 200);
	set_skill("yijinjing", 200);
  	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("puti-steps",250);
	set_skill("move",200);
	set_skill("dodge",200);
	
	map_skill("iron-cloth","yijinjing");
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "yijinjing");
	map_skill("force", "yijinjing");
    	map_skill("dodge","puti-steps");
    	map_skill("move","puti-steps");
    	
        set_skill("dual-attack",300);
	set_temp("apply/haste",300);

	setup();
        armor=new("/obj/armor/cloth");
	armor->set_name("�ƾɲ�����ɮ��",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
}