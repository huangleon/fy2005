#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��������", ({ "oldman" }) );
        set("long","һ���������ǵ����˼ң��������Ͽ����˽⵽��Ľ�����\n");
        
        set("age", 76);
		set("class","wudang");
		
	set("chat_chance",1); 
	set("chat_msg",	({
            	"�������������۳���̾��������ɽׯ�Ĺ�������̫���ˣ�����������\n����˭Ҫ���أ�\n",
         	"���������ĳ۵�����˵��һ����������������������磬��үү�����˲���ɽ��
��һƬ���־�˵������үү�����������ж����µ����󡣡�\n",
	}));

       
        set("combat_exp", 500000);

        set_skill("unarmed", 100);
		set_skill("force",200);
		set_skill("huntunforce",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
		set_skill("move",100);
		set_skill("taiji",85);
	
		map_skill("unarmed","taiji");
		map_skill("force","huntunforce");
	
		set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.nianzijue" :),
        }) );
	
	
	set("inquiry",	([
		"����" : "���긻��ɽׯ������ׯ����Ǳʯδ����ʱ������ɽׯ
�����Ǹ��󷱻����������£������Դ��ⲻ�����ġ����������̳м�
ҵ�󣬰�������һ��Ϳ�أ�һ����Ϳ���ݷõ������ˣ�����⼪����
Ҳ����˥������ࡣŪ�ô�ҵ����Ӷ��ٲ����ѡ�\n",
		"story" : "���긻��ɽׯ������ׯ����Ǳʯδ����ʱ������ɽׯ
�����Ǹ��󷱻����������£������Դ��ⲻ�����ġ����������̳м�
ҵ�󣬰�������һ��Ϳ�أ�һ����Ϳ���ݷõ������ˣ�����⼪����
Ҳ����˥������ࡣŪ�ô�ҵ����Ӷ��ٲ����ѡ�\n",
	])			);
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

