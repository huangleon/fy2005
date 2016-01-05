//TIE@FY3
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight();


void create()
{
    	set_name("����", ({ "master li", "master","li" }) );
    	set("gender", "����" );
    	set("nickname", HIG"ӵ��ɽׯ����"NOR);
    
    	set("age", 25);
   
    	set("reward_npc", 1);
    	set("difficulty", 30);
    
    	set("apprentice_available", 50);
    	create_family("��ɽ��", 3, "����");
    	set("rank_nogen",1);
    	set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    
    	set("long",
        	"���������µ�һ���������֮�ӣ�����ӵ��ɽׯ����������Ϊ������Ϊ��ɽ�����š�\n"
        	);
    	  set("inquiry", ([
                "�����" : "�Ҹ�������������ÿһ�������Ľ����о���֮���Լ�Ҳ����һ��������
�����˼���Ϊ����֮�£���û��һ�������ƽ���󣬵�ȴһֱ�޷�֤������Ҳ�������˼�ƽ
�������ź���Ҫ֤�������Ƿ���ľ�����������һ��Ҫ��һ������������������Ҫ�о�
�����书�������Ļ��ǣ�������Ҫ�зǳ��Ի͵�ս�����������ܹ���ඥ����֡�
 
����������������󣬲���֤�����������Ѳ���񽣡�\n",
                "cangqiong" : "�Ҹ�������������ÿһ�������Ľ����о���֮���Լ�Ҳ����һ��������
�����˼���Ϊ����֮�£���û��һ�������ƽ���󣬵�ȴһֱ�޷�֤������Ҳ�������˼�ƽ
�������ź���Ҫ֤�������Ƿ���ľ�����������һ��Ҫ��һ������������������Ҫ�о�
�����书�������Ļ��ǣ�������Ҫ�зǳ��Ի͵�ս�����������ܹ���ඥ����֡�
 
����������������󣬲���֤�����������Ѳ���񽣡�\n",       
       					"����":"�䵱ɽ�£��������У��������ǣ��������ݡ�\n",
        				"��":"�䵱ɽ�£��������У��������ǣ��������ݡ�\n",
        ]) );
        
    	set("combat_exp", 10000000);
    	set("score", 90000);
    
    	set_skill("unarmed", 200);
    	set_skill("blade", 250);
    	set_skill("force", 180);
    	set_skill("move", 160);
    	
    	set_skill("dodge", 200);
    	set_skill("qiusheng-blade", 200);
    	set_skill("xianjing", 150);
    	set_skill("liuquan-steps", 200);
    	set_skill("parry",200);
    	set_skill("perception",200);

    	map_skill("unarmed", "meihua-shou");
    	map_skill("blade", "qiusheng-blade");
    	map_skill("force", "xianjing");
    	map_skill("dodge", "liuquan-steps");
    	map_skill("parry","qiusheng-blade");	
    	    
    	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
    
    	setup();
    	carry_object(__DIR__"obj/greencloth")->wear();
    	carry_object(__DIR__"obj/yuhuan")->wield();
}


void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}

void attempt_apprentice(object ob)
{
/*        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����Ž����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
*/
	command("hehe");
	command("say ������ϲ,��ѧ���ʦ֮��,�ȷŷ���˵��");
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "����" )
          {      command("say ��ֻ���е��ӣ��㻹��ȥ���ҵķ��˰ɣ�");
          }
        else {

                command("smile");
                command("say ��ɽ���Ӵ���û�б���ʦ�ŵġ�");                
                command("say ��һ��Ҫ�������ɽ�ɵ��书��");
                command("recruit " + ob->query("id") );
                ob->set("once_huangshan",1);                
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huangshan");
        add("apprentice_availavble", -1);
}

int accept_fight(object me)
{
	return 0;
}

void init()
{
	::init();
	add_action("do_get","get");
}

int do_get(string arg)
{
    string what,where;
    object the_wall;
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,environment(this_object())) ;
    if (the_wall)
    if(the_wall->query("name") == "��ǽ")       
    {
        message_vision("$N��$n���һ�����󵨣����Ҵ��ȸ���������⣡\n",
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}


smart_fight()
{
	int i,j,count;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (who->query("kee")<6000) {
		count=0;
		for (j=0;j<sizeof(enemy);j++) {
			if (enemy[j]->is_zombie()) count++;
		}
		if (count>=3)
			command("perform zombie-wp1");
	}
	if (!random(3)&& who->query("kee")>8000) who->perform_action("blade.jingsheng");
	return;
}


int accept_object(object who, object ob)
{
	if(!who->query("marks/��ɽ����") || who->query("class")!="legend") return 0; 
	if( ob->query("name")!="��ѩ�ż�" ) return 0;
		message_vision(CYN"$N΢΢Ц�������ղ�������ʦ������ô��\n"NOR,this_object());
		message_vision(CYN"$N˵:һ·�������ˣ��ں���ЪϢ����ɣ������и�ͽ�ܣ��п����ǿ����д�һ�¡�\n"NOR,this_object());
		tell_object(who,HIW"�����а�ϲ���û��ᣡ���Գ˻�ѧ�����ˣ���\n"NOR);
		who->set("marks/��ɽѧ��",1);
		who->delete("marks/��ɽ����",1);
	return 1;
}