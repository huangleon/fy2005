#include <ansi.h>
inherit NPC;

int fill_water();
int quest();

void create()
{
	set_name("��ˮ�ĸ���",({"woman"}));
	set("long", "һ�����������ĸ��ˣ����ڷѾ�������Ƥ�ƴ���װˮ��\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 500000);
	set("gender","Ů��");
	
	set("inquiry", ([
 		"gumu":	"��Ŷ�̲�ϳ����ľ�����ЩĹ���ˣ��ҵ��ҵ�ǰЩ�����һ��ܴ����\n",
 		"�Ŷ�":	"��Ŷ�̲�ϳ����ľ�����ЩĹ���ˣ��ҵ��ҵ�ǰЩ�����һ��ܴ����\n",
 		"tomb":	"��Ŷ�̲�ϳ����ľ�����ЩĹ���ˣ��ҵ��ҵ�ǰЩ�����һ��ܴ����\n",
 		"�Ŷ�̲": "��Ŷ�̲�ϳ����ľ�����ЩĹ���ˣ��ҵ��ҵ�ǰЩ�����һ��ܴ����\n",
 		"��Ĺ":	"��Ŷ�̲�ϳ����ľ�����ЩĹ���ˣ��ҵ��ҵ�ǰЩ�����һ��ܴ����\n",
 		"�����Ʊ�": "��Ŷ�̲�ϳ����ľ�����ЩĹ���ˣ��ҵ��ҵ�ǰЩ�����һ��ܴ����\n",	
 		"��": "����ô����ʮ���ƽ��Ҿ������㡣\n",
 		"yu": "����ô����ʮ���ƽ��Ҿ������㡣\n",
 		"jade": "����ô����ʮ���ƽ��Ҿ������㡣\n",
 		"�Ŷ���":	(: quest() :),
   	]));
   		
	set("chat_chance", 2);
        set("chat_msg", ({
                "����˵����Ҳ�����ˮ�ɣ����˹ؾͿ����ˡ�\n",
                "�������������˵:����˵���Ĺ�ﶼ��"YEL"�����Ʊ�"GRN"����\n",
                (: fill_water() :),
        }) );
	set("sold",0);	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/d/guanwai/npc/obj/wineskin");
	carry_object(__DIR__"obj/bucket");
	
}

int fill_water() {
	command("fill bucket");
	return 1;
}

int accept_object(object who, object ob)
{
	object jade;
	if (ob->query("thief_obj")){
		command("ack");
		command("say �ⲻ�岻�׵Ķ������۲���Ҫ��");
		return 0;
	}
		
	
	if( ob->value() >= 300000) {
 	  	if (query("sold") || REWARD_D->riddle_check(who,"�Ͼ�֮��")!=3) {
          	if (objectp(query("buyer"))) 
           		command("say �������ˣ��ҵ���ո�"+query("buyer")->name()+"���ߡ�");
           	else
           		command("say �������ˣ��ҵ���ո������ߡ�");
           	return 0;
        }
        command( "say �ðɣ�������Ҿ������㡣");
        jade = new(__DIR__"obj/jade");
        if (!jade->move(who))
        	jade->move(this_object());
        else
        	message_vision("��ˮ�ĸ����������������$Nһ��������\n",who);
        set("sold",1);
        set("buyer",who);
        return 1;
    } else {
        command("say ��ô��Ǯ��ô���أ�\n");
        return 0;
    }
    return 0;
} 


int	quest(){
	object me = this_player();
	
	if (REWARD_D->riddle_check(me,"�Ͼ�֮��")!=2)	return 0;

	message_vision(CYN"$N���ɵؿ���$n����˵���㾹Ȼ֪���ҵ��ҵ����֣�����������\n",this_object(),me);
	tell_object(me,CYN"���˴�����������ĵ�˵��һ����ǰ����������ȥ�ˣ���˵�л�ǿ���д�������\n"NOR);
	tell_object(me,CYN"����˵������ǰ������һ��������Ҫ�ҿ��������㣡\n"NOR);
	REWARD_D->riddle_set(me,"�Ͼ�֮��",3);
	return 1;
}
		
	
		