// annie 07.04.2003
// dancing_faery@hotmail.com
// ע�⣺����ʽ�е�temp���ƶ��ཫ�ı�weaponӳ�䣬��������flag=0ȡ����ʱӳ�临�ơ�
// ע�⣺����ʽ�����Ƴ�Ŀ��Դԭ�����ԣ����������������
// ע�⣺����summon������NPC��ʹ��ʱ������possessed�����������Ҫ�ֶ��ı䡣
// ע�⣺ָ��ƹ�ȥ����С������ID��QUERY_ID���صĲ�ͬ�������ں��к�����Ŀ��ԴNAME/ID��
// ��Ӧָ�cpstat.c

#include <ansi.h>
#include <dbase.h>
#include <login.h>;

//	inherit F_CLEAN_UP;
/*
void create()
{
	seteuid(ROOT_UID);
}*/

// ------------------����Ϊ������еĴ����ļ�

mapping items=([]);
/* ��ʽΪ��
items = ([
	������	5
	�����ӣ� 1
]);	
*/
mapping query_qitems() { return items;}

// ���ش�������Ʒ��ʣ��ֵ
int add_qitems(string name, int amount)
{
	string *dir;
	int index;
		
    if( !mapp(items) ) {
    	items= ([ name: amount ]);
    	return amount;
    }	
    else {
    	dir = keys(items);
    	index = member_array(name,dir);
		if ( index != -1) {
//			CHANNEL_D->do_sys_channel("sys", "box = " + items[dir[index]] + " amount = "+amount+"\n");
			if (items[dir[index]]+ amount <=0){
				map_delete(items, dir[index]);
				return 0;
			}
			items[dir[index]] += amount;
			return items[dir[index]];
		}	
		else
			items[name]= amount;; 
    }	        	
}

void clear_items(){ items = ([]); }

void set_items(mapping t_items)	{		// this function is for transfering
	
	items = t_items;
	
}

// -------------------------

string ngstr(string str,int lng)
{
        int i,i2;
        string strc;
        strc=str;
        // filter color-code
		// annie 10.7.2004
        str=replace_string(str,CSI,"");
        
        str=replace_string(str,"2;37;0m","");

        str=replace_string(str,"41;","");
        str=replace_string(str,"42;","");
        str=replace_string(str,"43;","");
        str=replace_string(str,"44;","");
        str=replace_string(str,"45;","");
        str=replace_string(str,"46;","");
        str=replace_string(str,"47;","");
        str=replace_string(str,"1;","");
        str=replace_string(str,"30m","");
        str=replace_string(str,"31m","");
        str=replace_string(str,"32m","");
        str=replace_string(str,"33m","");
        str=replace_string(str,"34m","");
        str=replace_string(str,"35m","");
        str=replace_string(str,"36m","");
        str=replace_string(str,"37m","");
        str=replace_string(str,"38m","");
        str=replace_string(str,"40m","");
        str=replace_string(str,"41m","");
        str=replace_string(str,"42m","");
        str=replace_string(str,"43m","");
        str=replace_string(str,"44m","");
        str=replace_string(str,"45m","");
        str=replace_string(str,"46m","");
        str=replace_string(str,"47m","");
        str=replace_string(str,"1m","");


        // fill with space char


        i2=lng-strlen(str);
        for (i=0; i<i2/2; i++)
        {
                strc=strc+"��";
        }
        if (i2%2)
                strc=strc+" ";
        // return
        return strc;

}


string nrstr(string str,int lng,string prefix,string surfix,int ns)
{
	// ���¶��к�ʽ
	// ��ȥ�����ж��У�֮�󵽴�һ�������Զ�����
	// annie 11.11.2004

        int i,i2,i3,i4=0;
        string strc,std;


		if (!ns)
		{
			strc=replace_string(str,"\n","");

			i3 = strlen(strc);
			i2 = lng-strlen(prefix)-strlen(surfix);
			// ʵ���������ÿ�г���

			str = "";
			if (i4<i3-i2)
			{
				do 
				{
				str += prefix+strc[i4 .. i4+i2]+surfix;
				i4 += i2+1;
				}
				while (i4 < i3-i2);
			}

			str += prefix;
			str +=ngstr(strc[i4 .. i4+i2],i2+1);
			str += surfix;
		}
		else
		{
			std = str;
			i4 = 0;
			strc = "";
			str="";
			i3 = strlen(strc);
			i2 = lng-strlen(prefix)-strlen(surfix);
			do
			{
				i = strsrch(std,"\n");
				strc = std[0..i-1];

				str += prefix;
				str += ngstr(strc,i2+1);
				str += surfix;

				std = std[i+1..];
			}
			while (strsrch(std,"\n") != -1);

			str += prefix;
			str += ngstr(std,i2+1);
			str += surfix;

		}

        return str;

}


string annie_mimic(object ob, object ob1)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text,*tmp, id, spec;
    int loop;
	string tmp1,tmp2;
	int flag;
	mapping skl,map;
	string *sname,*mapped;

	flag = 0;	// �Ƿ�����ʱӳ�䣿1:���� 0:������

	seteuid(geteuid());

    list = (mapping)ob->query_entire_dbase();
    tlist = (mapping)ob->query_entire_temp_dbase();
    if( (!list || !mapp(list)) && (!tlist || !mapp(tlist)))
        return "Cpstat������Դû���κοɶ����ݡ�\n";
    
    if (sizeof(list))
    {
        klist = keys(list);
        klist = sort_array(klist, "sort_keys", this_object());
    }
    
    if (sizeof(tlist))
    {
        tlist2 = keys(tlist);
        tlist2 = sort_array(tlist2, "sort_keys", this_object());
    }
    
    if(!klist || !sizeof(klist))
        return "Cpstat������Դû���κοɶ����ݡ�\n";
    
	text = HIW"�����" + base_name(ob) + NOR"\n";
	for(loop=0; loop<sizeof(klist); loop++)
		ob1->set(klist[loop],list[ klist[loop] ]);
	text += "\n"HIW+sizeof(klist) + " ������������Ѹ��Ƶ� " +base_name(ob1)+ NOR"\n\n";

	if (flag)
	{
		text += HIW"�����" + base_name(ob) + NOR"\n";
		for(loop=0; loop<sizeof(tlist2); loop++)
			ob1->set_temp(tlist2[loop],tlist[ tlist2[loop] ]);
		text += "\n"HIW+sizeof(tlist2) + " ���ݴ�������Ѹ��Ƶ� " +base_name(ob1)+ NOR"\n\n";
	}

	skl = ob->query_skills();
	if (sizeof(skl))	// ����skills
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = ob->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
			ob1->set_skill(sname[loop],skl[sname[loop]]);	// �ȸ���skill��

		text += HIW+sizeof(skl) + " �������Ѹ��Ƶ� " +base_name(ob1)+ NOR"\n\n";

		for(loop=0;loop<sizeof(skl); loop++)
			if (ob->query_skill_mapped(sname[loop]))
				ob1->map_skill(sname[loop],ob->query_skill_mapped(sname[loop]));	// �ٸ���map
	}

//	ob1->set("chat_chance_combat",ob->query("chat_chance_combat"));
//	ob1->set("chat_msg_combat",ob->query("chat_msg_combat"));

    return text;
}



string annie_itemmimic(object ob1,mapping list,mapping tlist)
{
    mixed *klist, *tlist2;
    string text,*tmp, id, spec;
    int loop;
	string tmp1,tmp2;
	int flag;
	mapping skl,map;
	string *sname,*mapped;

	flag = 1;	// �Ƿ�����ʱӳ�䣿1:���� 0:������

	seteuid(geteuid());

    if( (!list || !mapp(list)) && (!tlist || !mapp(tlist)))
        return "Cpstat������Դû���κοɶ����ݡ�\n";
    
    if (sizeof(list))
    {
        klist = keys(list);
        klist = sort_array(klist, "sort_keys", this_object());
    }
    
    if (sizeof(tlist))
    {
        tlist2 = keys(tlist);
        tlist2 = sort_array(tlist2, "sort_keys", this_object());
    }
    
    if(!klist || !sizeof(klist))
        return "Cpstat������Դû���κοɶ����ݡ�\n";
    
	text = HIW"ԭ��Դ��" + NOR"";
	for(loop=0; loop<sizeof(klist); loop++)
		ob1->set(klist[loop],list[ klist[loop] ]);
	text += HIW+sizeof(klist) + " ������������Ѹ��Ƶ� " +base_name(ob1)+ NOR"\n\n";

	if (flag)
	{
		text += HIW"ԭ��Դ��" + NOR"";
		for(loop=0; loop<sizeof(tlist2); loop++)
			ob1->set_temp(tlist2[loop],tlist[ tlist2[loop] ]);
		text += HIW+sizeof(tlist2) + " ���ݴ�������Ѹ��Ƶ� " +base_name(ob1)+ NOR"\n\n";
	}


    return text;
}

string annie_skillcp(object ob, object ob1)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text,*tmp, id, spec;
    int loop;
	string tmp1,tmp2;
	int flag;
	mapping skl,map;
	string *sname,*mapped;

	seteuid(geteuid());

	skl = ob->query_skills();
	if (sizeof(skl))	// ����skills
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = ob->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
			ob1->set_skill(sname[loop],skl[sname[loop]]);	// �ȸ���skill��

		text = HIW+sizeof(skl) + " �������Ѹ��Ƶ� " +ob1->name()+ NOR"\n\n";

		for(loop=0;loop<sizeof(skl); loop++)
			if (ob->query_skill_mapped(sname[loop]))
				ob1->map_skill(sname[loop],ob->query_skill_mapped(sname[loop]));	// �ٸ���map
	}
	else
		text = HIW+ob->name()+HIW"û���κο��õļ��ܡ�\n\n"NOR;

    return text;
}

string annie_attcp(object ob, object ob1)
{
	string *att = ({"str", "cor", "dur", "agi", "spi", "con", "per", "int", "kar","cps","fle", "tol",
			"max_kee","max_gin", "max_sen", "kee", "gin", "sen", "eff_kee", "eff_gin", "eff_sen",
			"max_force", "max_atman", "max_mana", "force", "atman", "mana", 
			"combat_exp" });
	int loop;
	string text;
		
	for (loop=0; loop<sizeof(att);loop++)
		ob1->set(att[loop],ob->query(att[loop]));
					
	text = HIW + ob->name() + HIW"�Ļ��������Ѿ����Ƶ�" + ob1->name() + HIW"�С�\n"NOR;
	return text;
}		

// ֻ�Ǹ���ability,û��ability�ĵ�������			
string annie_abilitycp(object ob, object ob1)
{
	mapping skl;
	string *sname, text;
	int loop;
	seteuid(geteuid());
	
	text = WHT""+ob->name()+"û��ABILITY\n"NOR;
	
	ob1->delete("ability");
	skl = ob->query("ability");
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		for(loop=0;loop<sizeof(skl); loop++)
			ob1->set("ability/"+ sname[loop],skl[sname[loop]]);	
		text = HIW+sizeof(skl) + " ��ABILITY�Ѹ��Ƶ� " +ob1->name()+ NOR"\n";
	}
	
	ob1->delete("ability2");
	skl = ob->query("ability2");
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		for(loop=0;loop<sizeof(skl); loop++)
			ob1->set("ability2/"+ sname[loop],skl[sname[loop]]);	
		text += HIW+sizeof(skl) + " ��ABILITY�Ѹ��Ƶ� " +ob1->name()+ NOR"\n\n";
	}
	
	ob1->set("Add_mana/ability", ob->query("Add_mana/ability"));
	ob1->set("Add_force/ability", ob->query("Add_force/ability"));
	ob1->set("Add_atman/ability", ob->query("Add_atman/ability"));
	
	return text;
}		
			

int mutant()
// ʹgold robot�Ķ������
{
	int rate;
	int seed = random(7)+1;
	mapping buff;

	rate = query("mutant_rate");

	if (random(100) > rate)
		return 0;
	
	set("mutant",seed);

	if (query("mutant_name"))
		set("name",HIB+query("name")+NOR);
	
	switch (seed)
	{
	case 1:	// Extra Life
		set("max_kee",query("max_kee") * 20);
		set("eff_kee",query("max_kee"));
		set("kee",query("max_kee"));
		set("max_sen",query("max_sen") * 20);
		set("eff_sen",query("max_sen"));
		set("sen",query("max_sen"));
		set("max_gin",query("max_gin") * 20);
		set("eff_gin",query("max_gin"));
		set("gin",query("max_gin"));
		return 1;
		break;
	case 2:	// Immune to Physics Attack
		set("resistance/kee",100);
		return 1;
		break;
	case 3: // Super Shield
		set("resistance/sen",100);
		set("resistance/gin",100);
		set("max_mana",20000);
		set("mana",20000);
		set_temp("shield_force/type","mana");
		set_temp("shield_force/ratio",10000);
		set_temp("shield_force/msg",
			MAG"$N"MAG"��ʽ����$n"MAG"��ǰ����֮�⣬������ţ�뺣����ʧ�������С�\n"NOR);
		return 1;
		break;
	case 4: // Immune to Busy
//		set_temp("no_busy",100);
		set("immune_busy",4);
		return 1;
		break;
	case 5: // Extra Strength
		set("str",query("str")*(150+random(100))/100);
		set("force_factor",query("force_factor")*(150+random(100))/100);
		return 1;
		break;
	case 6: // Extra Combat Exp
		set("combat_exp",query("combat_exp")/150*(100+random(100)));
		return 1;
		break;
	case 7: // Damage Shield
		set_temp("damage_shield/type","kee");
		set_temp("damage_shield/amount",query("str") * query("str") * query("str") /100 * query("str") / 32);
		set_temp("damage_shield/msg",HIW"$nһ��$N��������Ȼ��������\n"NOR);
		return 1;
		break;
	}
	
	return 1;
}

void tell_team(object who,string what)
{
	object *team;
	int i; 
	object ob,me=who;
	team=pointerp(who->query_team()) ? who->query_team() : ({ who });
	if(team)
	{
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			tell_object(team[i],what);
		}
	}
	return ;
	
}

object team_check(object who,string what,int flag,mixed dat)
{
	object *team;
	int i; 
	object ob,me=who;

	// flag = 0: ֻ������ͬ������ɼ�team mate��������
	// flag = 1: ����������teammate��������
	// flag = 2: ֻ������ͬ������ɼ�team mate����������
	// flag = 3: ����������team mate����������
	team=pointerp(who->query_team()) ? who->query_team() : ({ who });
	if(team)
	{
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			if (team[i] == me && flag >= 2) continue;
			if ( (flag == 0 || flag == 2) 
				&&	(environment(team[i]) != environment(me) || ( !me->visible(team[i])) )) 
				continue;

//			message_vision(team[i]->query(what)+"|||"+dat,team[i]);

			if (team[i]->query(what) == dat)
				return team[i];
		}
	}
	return 0;
}

mapping mapping_copy(mapping map)
{
	mapping dest = ([ ]);
    mixed *klist;

    if (sizeof(map))
        klist = keys(map);
	else
		return 0;
    
    if(!klist || !sizeof(klist))
        return 0;
    
	for(int loop=0; loop<sizeof(klist); loop++)
		dest[klist[loop]] = map[ klist[loop] ];

	return dest;
}

int get_highest_skill_level(object me,int i)
{
    int loop;
	int flag,lv=0;
	mapping skl,map;
	string *sname,*mapped;
	
	skl = me->query_skills();
	if (sizeof(skl))
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		
		map = me->query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
			if (skl[sname[loop]] > lv)
				lv = skl[sname[loop]];
	}
	return lv;
}

int block_account(object me)
{
	object ob;
	tell_object(me,HIW"����ʺ������쳣������ϵͳ��ʱ��ֹʹ�á�\n����ϵSilencer@Fengyun.com���Խ����\n"NOR);
	"/cmds/adm/block"->main(this_object(),me->query("id"));

	return 1;
}


int check_legitimate_state(object me)
{
	// �˺�ʽֻ���4.1��2003��10��ʱ��design.

	if (wizardp(me) && me->query("env/debug"))
		return 1;
	
	// 1. Attributes
	if (me->query("str") >= 90)	// Unarmed 300+?
	{
		block_account(me);
		return 0;
	}

	if (me->query("int") > 80)	// Without Enhance(Removed in 4.1), int capped @ 30
	{
		block_account(me);
		return 0;
	}

	if (me->query("agi") > 85 || me->query("con") > 85 
		|| me->query("cps") > 85 || me->query("kar") > 85 )	// Limit dur,agi,con,cps,kar,fle,spi.
	{
		block_account(me);
		return 0;
	}

	if (me->query("force_factor") > 150)
	{
		block_account(me);
		return 0;
	}
	
	// 2. Combat Exp
	if (me->query("combat_exp") > 12000000)
	{
		block_account(me);
		return 0;
	}

	// 3. Skill level
	if (get_highest_skill_level(me,0) > 450)
	{
		block_account(me);
		return 0;
	}

	// 4. Max gin/kee/sen, Could player reach/over 40K in 4.1?
	if (me->query("max_gin") > 30000 
		|| me->query("max_kee") > 40000 
		|| me->query("max_sen") > 30000)
	{
		block_account(me);
		return 0;
	}

	return 1;
}
