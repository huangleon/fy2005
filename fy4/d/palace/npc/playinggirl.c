#include <ansi.h>
inherit NPC;
void create()
{
	int i,amun;
	string *name= ({"����", "�Ϸ�", "����", "����", "����"});
	set_name( name[random(5)] , ({ "playing girl", "girl" }) );
	set("long", "����һλ�����ȵ�СѾͷ��ר��������壮\n");
	set("attitude", "friendly");
	set("age", 13);
        set("gender", "Ů��" );
        set("chat_chance", 1);
        set("chat_msg", ({
                "СѾͷ���Ե�����˵Ҫ��������ʱ�����������ſϣ�\n",
        }) );

	set("combat_exp", 200000);

	set_skill("throwing",250+random(100));
	set_skill("dodge", 50+random(50));

	setup();
	carry_object("/obj/armor/cloth")->wear();
	
	if (random(3)>1) {carry_object(__DIR__"obj/pai1");
				carry_object(__DIR__"obj/pai2");
				}
		else if (random(3)>0) {
			carry_object(__DIR__"obj/pai2");
			carry_object(__DIR__"obj/pai3");
			}
		else {
			carry_object(__DIR__"obj/pai3");
			carry_object(__DIR__"obj/pai1");
			}
}
