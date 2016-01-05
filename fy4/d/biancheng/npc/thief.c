inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
int do_attempt(string arg);

void create()	
{
        object weapon;
        
        set_name("˾������", ({ "sikong taoxing","sikong"}) );
        set("long","˾��������˾��ժ�ǵ��õܣ���ڼ�����µڶ���͵��\n");
        set("gender", "����" );
    	set("env/wimpy",20);
		
		set("nickname", YEL"Գ��"NOR);
        set("title",WHT"���µڶ���͵"NOR);
		
        set("chat_chance", 1);
        set("chat_msg", ([
        	"���µ�һ��͵":	"����λ�Դ�֮���ҿɲ���ժ����ô����Ƥ��\n",
        	"���µ�һ":	"����λ�Դ�֮���ҿɲ���ժ����ô����Ƥ��\n",
        	"˾��ժ��":	"ժ����ʲôϡ�棬Ҫ�����Ĳ����汾�£�\n",
        	"˾��":		"ժ����ʲôϡ�棬Ҫ�����Ĳ����汾�£�\n",
        	"����":		"��������������������\n",	
        	"��͵":		"���ºų���͵�ĺܶ࣬������ô�����ʵѧ�ľͺ����ˡ�\n",
        	"����":		"����Ժ�Ǻ����ң���������͵��Ǳ����\n",
        	"����":		"����Ժ�Ǻ����ң���������͵��Ǳ����\n",	
        ]) );

         set("inquiry",([
        ]) );

		set("age", 34);
        
        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 6000000);
    
        set_skill("perception", 200);
        set_skill("move", 400);
        set_skill("monkey-claw",200);
        set_skill("dodge", 200);
        set_skill("unarmed",200);
        set_skill("stealing",321);
        set_skill("betting",300);
        
        map_skill("unarmed", "monkey-claw");
              
        setup();
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(HIR BLK"��������մ������ĳ�����"NOR, ({ "cloth" }) );
        weapon->set("long","��������մ������ĳ�����(Cloth)��");
        weapon->set("value",0);
        weapon->wear();

}


void init()
{
        object ob;
        ::init();
        add_action("do_attempt","apprentice");

}


void smart_fight() {
	message_vision(CYN"\n˾������˵�������ˣ�ವ�һ��������������ʧ�ˡ�\n"NOR,this_object());
	destruct(this_object());
}


int do_attempt(string arg)
{
        object ob;
        ob = this_player();
        
        if (!arg || arg!= "sikong" && arg!="sikong taoxing"){
        	tell_object(ob,"�����˭?\n");
        	return 1;
        }
        if (REWARD_D->check_m_success(ob,"��͵����")) {
        	command("say ͽ�ܹԣ�ʦ������ţ���������������");
        	return 1;
        }
        
        if (REWARD_D->riddle_check(ob,"��͵����")==2) {
        	command("say ���ȵ�֤�����Լ������Ͳ��С�");
        	return 1;
        }
        	
        if (!REWARD_D->riddle_check(ob,"��͵����") || !ob->query_temp("marks/wanma/app_sikong")) {
        	message_vision("˾������һ������������˵����������ʣ���ô������ͽ���أ�\n\n",ob);
        	ob->set_temp("marks/wanma/app_sikong",1);
        } else if (ob->query_temp("marks/wanma/app_sikong")==1) {
        	message_vision("˾������˵�����в��У����������ͽ�ܣ����²��͵�������͵�ˣ�\n",ob);
        	ob->set_temp("marks/wanma/app_sikong",2);
        } else {
        	message_vision("˾����������Ц��˵����Ȼ��������֮���Ҿ���ǿ��Ӧ�ˡ�\n\n",ob);
        	command("say ������������ͽ�ܣ��ҵ��ȿ����㡣");
        	REWARD_D->riddle_set(ob,"��͵����",2);
        	command("say ����ε��ر���������Ϊ���������ϼ����㡣");
        	command("say û�뵽��������������������Һܲ���ò���ܲ���ò���������˶����ҡ�");
        	command("say ������һ��֮�£��������м�����������������������������Ƕ���̫�������Դ���������");
        	command("say ������ܰ��������������������ң��Ҿ�������ͽ���ˡ�");
        }
        	
        return 1;
}

                        
int prevent_learn(object me, string skill)
{
      command("emote һ�����ŵĿ�����˵����������ˣ��񲻾���������˾�����ǣ�");
      command("emote ��ͷҡ�����˹��Ƶģ����У����С�");
      return 1;
}


int accept_object(object me, object obj)
{
		string *material_names=({ "����","����","�����µ���" });
		string ob_name;
		int success, makeup_ok,i;
		object book;
		
		
		if (!REWARD_D->riddle_check(me,"��͵����")) {
			command("say ��˾������ʲô�����㲻�����Ķ��õ�������Т����");
			return 0;
		}
		
		ob_name= obj->query("name");
		success=1;
		makeup_ok=0;
		for(i=0;i<3;i++)
		{
			if(ob_name==material_names[i])
			{
				if(me->query_temp("marks/wanma/sikong/"+ob_name))
				{
					command("say �ⶫ���㲻�Ǹ������ˣ��ѵ�ԭ���Ǹ��Ǽٵģ���\n");
					return 0;
				}
				me->set_temp("marks/wanma/sikong/"+ob_name,1);
				command("say �ã������������������¡�");
				makeup_ok=1;
			}
			success=success*me->query_temp("marks/wanma/sikong/"+material_names[i]);
		}
		if(!success) return makeup_ok; 
			
		me->delete_temp("marks/wanma/sikong");	
		
		tell_object(me,CYN"˾������˵����ѽѽ���㾹Ȼ���ҵ��ˣ��ܺá��ܺá�
˾�����ǰ�����ָ������˵�����ҳ������������Ѿ����ҵĵڶ�����ʮ�߸�ͽ���ˡ�\n"NOR);
		tell_object(me,CYN"˾������˵��ʦ����æ��Ҫ�̺ܶ�ͽ�ܣ����㱾�����Լ�ȥ�����ɡ�\n"NOR);
		book = new(BOOKS"foreknowledge_75");
		book->move(me);
		message_vision(CYN"\n˾������˵�������ˣ�ವ�һ��������������ʧ�ˡ�\n"NOR,this_object());
		REWARD_D->riddle_done(me,"��͵����",50,1);       
        return 1;
}
