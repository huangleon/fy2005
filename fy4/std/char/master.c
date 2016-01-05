#include <dbase.h>
#include <login.h>
#include <ansi.h>

int prevent_learn(object me, string skill)
{
    	mapping my_family, family;
    	int	betrayer, mylvl, lvl;

    	lvl = this_object()->query_skill(skill, 1);
    	mylvl = me->query_skill(skill, 1);
    	if( betrayer = me->query("betrayer") )
    	{
        	if( mylvl >= lvl - betrayer * 20 )
        	{
            	message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�\n"
                           "Ҳ��������$p��ǰ����ʦ�ŵ�����\n...��\n",
                	           this_object(), me );
            	command("say �� .... \nʦ���ܽ���Ķ����ˣ����������Լ����ɡ�");
            	return 1;
        	}
    	}

    	if( !me->is_apprentice_of(this_object()))
    	{
	        if( !mapp(my_family = me->query("family")) )  return 0;
	        if( !mapp(family = this_object()->query("family")) ) return 0;
	        if((my_family["family_name"] == family["family_name"]) )
	        {
	            command("hmm");
	            command("pat " + me->query("id"));
	            command("say ��Ȼ����ͬ�ţ������㲢���ҵĵ��ӣ�"
	                    "�㻹��ȥ����ʦ��ѧ��....");
	            return 1;
	        }
    	}

    	return 0;
}
	
string std_rank_title(object student)
{
    	int exp,i,gen;
    	string* ranks;
    	int * rank_levels;
    	string title;

    	ranks=query("ranks");
    	rank_levels=query("rank_levels");
    	if(!arrayp(rank_levels))
//        	rank_levels= ({76000,466000,1305000,2224000,3788000,
//                       4945000,10000000});
		rank_levels = ({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999});
					
    	if(!arrayp(ranks) || sizeof(rank_levels)+1 != sizeof(ranks))
    	{
        	if(!title = query("student_title"))
            		title = "����";
    	}        
    	else
    	{
        	exp = (int) student->query("combat_exp");
        	for(i=0;i<sizeof(rank_levels);i++)
            		if(exp < rank_levels[i]) break;
        	title=ranks[i];
    	}
    	// if(!stringp(ranks[i])) title=?
    	return title;
}

void re_rank(object student)
{
 	int exp;
    
    	student->assign_title(std_rank_title(student),query("rank_nogen"));
}

int recruit_apprentice(object ob)
{
    	mapping my_family, family;
    	if( ob->is_apprentice_of( this_object() ) )	return 0;
    	if( !mapp(my_family = query("family")) ) return 0;
    	family = allocate_mapping(sizeof(my_family));
    	family["master_id"] = query("id");
    	family["master_name"] = query("name");
    	family["family_name"] = my_family["family_name"];
    	family["generation"] = my_family["generation"] + 1;
    	family["enter_time"] = time();
    	// privs = 0 for general 
    	family["privs"] = 0;
    	ob->set("family", family);
    	if (ob->query("class")!= query("class"))
    		ob->add("once_menpai/"+query("class"), 1);
    	ob->set("class", query("class"));
    	re_rank(ob);
    	return 1;
}


string 	query_chinese_class (string e_class) {
	
	if (!e_class)	return "��";
	switch (e_class) {
		case	"assassin":	return "��Ǯ��";
		case 	"bat":		return "����";
		case	"ninja":	return "����";
		case	"legend":	return "��ѩ";
		case	"huashan":	return "��ɽ";
		case	"official":	return "�ٸ�";
		case	"beggar":	return "ؤ��";
		case	"fugui":	return "����ɽׯ";
		case	"shaolin":	return "����";
		case	"lama":		return "������";
		case	"wudang":	return "�䵱";
		case	"taoist":	return "����";
		case	"bonze":	return "�˹�����";
		case	"shenshui":	return "��ˮ��";
		case	"fighter":	return "��÷ɽׯ";
		case	"demon":	return "ħ��";
		case	"swordsman":	return "��ɽׯ";
		case	"knight":	return "�����";
		case	"yinshi":	return "������";
        case    "baiyun":   return "���Ƴ�";
		case	"huangshan":	return "��ɽ";
		case	"wolfmount":	return "��ɽ";
		case	"moon":	return "����칬";
		default:		return "��";
	}
}

//	Master protecting player students.
//	You need add an action do_kill in init() for it to work.

int do_killing(string arg)
{
    	object player, victim;
    	string id,id_class,kill_msg;
    	
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
		return notify_fail("����û������ˡ�\n");
    	if(living(victim))
    	{
	        if (ANNIE_D->check_buff(victim,"fugitive"))	return 0;
	        id_class=victim->query("class");
	        id=victim->query("id");
	       	if(id_class == query("class") && userp(victim) && player!=victim)
	        {
            		kill_msg = query("guard_msg")? query("guard_msg") : HIW"$N��$n�ȵ������ҵ��ӣ�̫�����˰ɣ�\n"NOR;
            		message_vision(kill_msg, this_object(),player);
					this_object()->kill_ob(player);
            		player->kill_ob(this_object());
            		player->perform_busy(2);
            		return 0;
        	} 
    	}
    	return 0;
}	

int is_master(){
	return 1;
}