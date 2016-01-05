// keeper.c
#include <ansi.h>
inherit NPC;

int hubby();

void create()
{
        set_name("��ϼ", ({ "lixia" }) );
        set("gender", "Ů��" );
        set("age", 24);
		set("per",5);
        set("long","���Ů�˿�������ʮ�����ˣ���������׳�����Σ�����ã�������\n");
        set("combat_exp", 4000);
        set("chat_chance", 1);
        set("chat_msg", ({
				"��ϼ�����ֹ���û�뵽��������ô���֣����ǿ�����Ϊ�ϡ�\n",
        }) );
        
        set("inquiry",	([
            	"��ɲ��":"action��ϼ����ԥԥ�ؿ�����˵�������ӿɲ��ܰ׸���\n",
            	"������": (: hubby() :),
            	"ըҩ": 	"��ȥ�ҵ����ҿ�����",	
            	"�׸�":		(: command("heihei") :),
        
        ]));
        
        set("attitude", "friendly");
        setup();
}

int accept_object(object who, object ob)
{
        int val;
        string msg;

		if (REWARD_D->riddle_check(who,"��ȡ��ɲ")==3) {
			if ( !ob->query("explosive")) {
				command("say ���������ʲô��Ҳû�С�");
				return 0;
			}
			if (ob->query("explosive") == 1 ){
				if (ob->query("name")=="�׻���")
					tell_object(who, CYN"
��ϼ���˿��׻���˵�����������õĻ�ҩ����������ֻ�ǣ��㿴��������׻���
�Ѿ��ܳ��ˡ���������Ȼ��������һ���ͻ��еڶ����������Ǹ��������ң���֪
�������׶����������Ƕ���ɽѨ�жڻ���һ����ҩ��\n"NOR);
				else
					tell_object(who,CYN"��ϼ�����˵�����в��У��������̫�\n"NOR);
				return 0;
			}
			command("say �ã��㵽���ӣ�ȥ����ɲ��ը��Bomb�����������Ǿ������ˡ�");
			return 0;
		}		
		
        if (!who->query_temp("marks/lixia_m"))
        {
        	message_vision(CYN"��ϼ˵��Ǯ�����һ���Ҫ��ǧ��ǵñ���Ҳ���֮��˵��ȥ��\n"NOR,who);
        	return 0;
        }	
        
        val = ob->value();
        
        if( val >= 100000 ) 
		{
        	msg = "�Ұ������ڱ��������ˣ�Ҫ�þ���Ҫ����ը��������������󺮣�
�������ߣ�Ѱ����ըҩ���²��У���ȥ�ҵ����ҿ�����\n";
			message_vision(CYN+msg+NOR, who);
			REWARD_D->riddle_set(who,"��ȡ��ɲ",3);
        	return 1;
		}
		msg = "��ô�㣬�һ�ָ�������°뱲���ء�\n";
		message_vision(CYN+msg+NOR, who);
		return 0;
}


int hubby(){
	
		object who = this_player();
		
		if (REWARD_D->riddle_check(who,"��ȡ��ɲ")!=2)
        {
        	command("say �����ӣ������Ǹ�ר��Ȣ����ɱ���ŵģ�");
        	command("shiver");
        	return 1;
        }
        
        message_vision(CYN"
��ϼ̾�˿���˵����Ȼ�������Ѿ����������ˣ��һ��Ǳ���Ҫ���������ɣ�ʮ�����ӣ�
�ҿ��Դ����˵أ������Ӿ������������ˣ�\n"NOR, who);
        who->set_temp("marks/lixia_m",1);
        return 1;
}
        
        
        
        	