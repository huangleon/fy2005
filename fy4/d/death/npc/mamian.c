#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����"NOR, ({ "mamian" }) );
        set("gender", "����" );
        set("age", 25);
		set("title", HIW "����"NOR);
 
        set_temp("apply/astral_vision",1);
	    set("intellgent",1);
        set("attitude", "peaceful");
        
        set("long",     "��������ȫ�����ϵĹ�֡�\n");
		
		set("inquiry", ([
          	"���̲�" : 	"action����ߴߴ����һ���ҽУ���ϧ��ʲôҲ��������\n",
      	]) );
		
        set("combat_exp", 30000);
        set_skill("parry",100);
        set_skill("hammer", 120);
		set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/hammer")->wield();
		carry_object("/obj/armor/ghost_cloth")->wear();
}

int accept_object(object who, object ob)
{
		message_vision("$N��$n�ֽ�һ�������������������˰ɣ�\n",this_object(),who);
		return 1;
}
