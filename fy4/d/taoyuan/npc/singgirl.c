
inherit NPC;
void create()
{
	set_name("����", ({ "lianer", "lian er", "����" }) );
	set("gender", "Ů��" );
	set("age", 21);
	set("title", "����Ů");
	set("long",
	"������Ϲ�ϵ���Ů��������һ�ں���������Ҳ����ó������ˣ���
ü�����ƺ����лӲ�ȥ���ǳ
\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set_skill("unarmed",30);
	set_skill("dodge",80);

	setup();
   carry_object(__DIR__"obj/cloth")->wear();
}

void do_sing(object ob)
{
   switch(random(2)) {
      case 0:
         message_vision("$Nת������$nӯӯ�ĵ��˸��򸣡�\n\n",this_object(),ob);
         break;
      case 1:
         message_vision("$N����ͷ��$nӯӯ�ĵ��˸��򸣡�\n\n",this_object(),ob);
         break;
   }
   this_object()->set_temp("marks/song", random(2));
   this_object()->set_temp("marks/songa", 0);
   call_out("singing",2, this_object());
}

int singing (object ob)
{
   int	song, songa;
   object laodie;

   remove_call_out("singing");
   song = ob->query_temp("marks/song");
   songa = ob->query_temp("marks/songa");
   switch(song) {
      case 0:
         switch(songa) {
            case 0:
               message_vision("$N����������\n",ob);
               message_vision("        һ����һ�꣬һ��ûһ�գ�һ����һ�һ����һ����\n",ob);
               ob->set_temp("marks/songa", 1);
   call_out("singing",2,ob);
               break;
            case 1:
               message_vision("        һ��һ���һϲһ����һ�һ���ԣ�һ��һ���\n",ob);
               ob->set_temp("marks/songa", 2);
   call_out("singing",2,ob);
               break;
            case 2:
               message_vision("        Ѱһ���ʶ����һ����һ�ᣬ��һ����֪����һ�أ���һ�ء�\n\n",ob);
               laodie = present("lao die", environment(ob));
               if(objectp(laodie)) {
                  laodie->delete_temp("marks/sing");
               }
               break;
         }
         break;
      case 1: 
         switch(songa) {
            case 0:
   message_vision("$N������壬����������\n",this_object());
   message_vision("  ����·������·���ϱ�·�������̡������̡�ʮ���̡�\n",this_object());
               ob->set_temp("marks/songa", 1);
   call_out("singing",2,ob);
               break;
            case 1:
   message_vision("  ��һ������һ������һ������ʱ����Ҳĺ����Ҳĺ����Ҳĺ��\n",this_object());
               ob->set_temp("marks/songa", 2);
   call_out("singing",2,ob);
               break;
            case 2:
   message_vision("  б�������̣�����������أ�Ĳ�ɽ������ˮ��������������\n",this_object());
               laodie = present("lao die", environment(ob));
               if(objectp(laodie)) {
                  laodie->delete_temp("marks/sing");
               }
               break;
         }
         break;
   }
}
