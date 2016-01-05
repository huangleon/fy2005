#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
    set_name("��ѩ", ({ "still" }) );
    set("nickname",CYN"������"NOR);
    set("title", "��ɽ�� ��ʮ�˴�����");
    set("combat_exp",9000000);
    set("class","huashan");
    set("gender", "Ů��" );
    set("age", 22);
    set("per", 50);
    set("force_factor",200);
    set("attitude", "friendly");
    set("skill_public",1);
    
    set_skill("dodge", 200);
    set_skill("move", 200);
    set_skill("anxiang-steps", 200);
    set_skill("cloud-dance", 200);
    set_skill("qingfeng-sword", 200);
    set_skill("sword", 200);
    set_skill("hanmei-force", 200);
    set_skill("dual-attack", 300);
    set_skill("advanced-unarmed", 300);
    set_temp("apply/haste",300);
    set_skill("force", 200);
    set_skill("unarmed", 400);
    set_skill("iron-cloth", 200);
    set_skill("spring-water", 200);
    map_skill("iron-cloth","spring-water");
    map_skill("sword","qingfeng-sword");
    map_skill("dodge","cloud-dance");
    map_skill("force","hanmei-force");
    map_skill("move","anxiang-steps");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
		(: perform_action, "dodge.yexuechuji" :),
      }) );

    setup();

    carry_object("/d/cave/npc/obj/windsword")->wield();
    carry_object("/d/huashan/npc/obj/ycloth")->wear();

}
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
