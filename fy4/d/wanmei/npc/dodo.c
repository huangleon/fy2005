inherit NPC;
void create()
{
    	set_name("��˿ȸ", ({ "sparrow" }) );
        set("race", "����");
        set("age", 1);
        set("gender", "����");
        set("long", "һֻ�����Ľ�˿ȸ \n");
    	set("combat_exp", 3000);
        set("attitude","peaceful");

        set_temp("apply/dodge", 100);
	set("chat_chance", 7);
        set("chat_msg", ({
        	"С��˿ȸߴߴ�ĽУ� \n",
        	"��˿ȸ����������ë�� \n"
        }) );
        setup();
}
