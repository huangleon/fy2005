
inherit NPC;
#include <ansi.h>
void create()
{
	object weapon;
        set_name("С���", ({ "servant" }) );
        set("gender", "����" );
        set("long","
����ӳ����൱���㣬�°���һ������Ӷ�û�У�˵��ϸ��ϸ����
"
	);
	
        set("age", 24);
        set("attitude","friendly");
        
        set("combat_exp", 0);
        
        set("score", 20000);

		set("no_arrest",1);

		set("chat_chance", 1);
        set("chat_msg", ({
                "��ӵ����������ӣ����˿������������⣬�����ǣ�����\n",
                "��ӳ�����󵨵��񣬾��Ҷԣ�������\n",
                "��ӻŻ����ŵؿ�����Χ���ۣ����������������ӣ����ǻ�������ȥ�ɡ�\n",
        }) );
        

        setup();
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("����������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("��ȸβ��ñ", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();

}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
