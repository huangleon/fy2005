// ; annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave();

void create()
{
	object weapon;
    set_name("Ѧ����", ({ "master xue", "master", "xue" }) );
    set("nickname", YEL"����"NOR);
	set("gender", "Ů��");
        set("age",19);
         set("long",
"��ɫˮ���䣬�·��в㵭�����������������·���һ����������Ӱ��
�ƿ������֣��¹⵭������������ǡ�������������ϡ��԰׵Ĺɣ��԰���
�¡�\n"
        );

	set("combat_exp", 90000000);
	set("NO_KILL",1);
    set("score", -10000);

    set("class", "moon");
    set("reward_npc", 1);
    set("difficulty", 10);

	set("no_fly",1);
	set("no_arrest",1);

    set("force", 3000);
    set("max_force", 3000);
    set("force_factor", 100);
    set("atman", 1400);
    set("max_atman", 1400);
    set("mana", 2000);
    set("max_mana", 2000);

    set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",70);
	
    set("apprentice_available", 1);

    create_family("��¹�", 3, "����");
	set("title","��¹�");

    set("rank_nogen",1);

    set_skill("literate", 150);
	set_skill("parry", 170);
	
	set_skill("perception", 300);
	set_skill("throwing", 300);
	set_skill("starrain", 200);

	set_skill("force", 180);
	set_skill("snowforce", 140);

	set_skill("blade", 150);
	set_skill("chillblade", 150);

	set_skill("dodge", 220);
	set_skill("move", 220);
	set_skill("stormdance", 200);

	map_skill("throwing","starrain");
    map_skill("parry", "chillblade");
    map_skill("blade", "chillblade");
    map_skill("move", "stormdance");
    map_skill("dodge", "stormdance");
    map_skill("force", "snowforce");

    setup();

	set("env/no_teach",1);			// duh, almost got me
	
	weapon = carry_object("/obj/armor/cloth");
	weapon->set("name",WHT"��ѩ��ɴ"NOR);
	weapon->set("long","һ�����л��޵��ذ�ɴ�¡�");
	weapon->wear();
	weapon=carry_object("/questnpc/obj/yueshenblade");
	weapon->wield();

}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
