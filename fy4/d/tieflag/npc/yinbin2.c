// yinbin.c
inherit NPC;
int go_shishi(object);
void create()
{
    	set_name("����",({"yin bin","yin","bin"}));
    	set("long","���������������ɴ����Լ��¶�������������������þ��ˣ�����������ҩ�����￴��\n");
    	set("gender","Ů��");
    
    	set("age",42);
    	set("no_arrest",1);
    	set("combat_exp",2200000);
    
    
    set_skill("force",100);
    set_skill("nine-moon-force",100);
    set_skill("unarmed",150);
    set_skill("nine-moon-claw",120);
    set_skill("nine-moon-steps",120);
    set_skill("parry",120);
    set_skill("dodge",120);
    set_skill("move",120);
    
    map_skill("move","nine-moon-steps");
    map_skill("force","nine-moon-force");
    map_skill("unarmed","nine-moon-claw");
    map_skill("dodge","nine-moon-steps");
    
    set("attitude", "friendly");
    set("inquiry",([
    	"����" : (: go_shishi :),
    	"man" : (: go_shishi :),
    ]) );
    set("chat_chance",5);     
    set("chat_msg",({
          "����˵������лл���������ҡ���\n",
          "����Ц����������������úܺá���\n",
          "�����ʵ������������������ˣ���\n",
          }) );

    setup();
    carry_object(__DIR__"obj/redcloth")->wear();
    carry_object(__DIR__"obj/redjin")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    command("lovelook");
    return 1;
} 


go_shishi()
{
      object me,shishi;
      string myfile;
	me=this_player();
      if (!(shishi=find_object(AREA_TIEFLAG"shishi")))
      	shishi=load_object(AREA_TIEFLAG"shishi");
      command("say Ҳ�ã�����ȥ�������ɡ�");
      tell_object(me,"������һ�ӣ����Ȼ����������ת������\n");
      me->move(shishi);
      return 1;
}

