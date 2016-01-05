// team.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

static object leader, *team;

string random_team_name(){
	string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
	});
	return lname[random(200)] + "�Ұ�";
}

int set_leader(object ob)
{
	if( ob==this_object() )
		error("set_leader: Cannot set this_object() as leader.\n");
	leader = ob;
}

object query_leader() { return leader; }

int follow_path(string dir)
{
// check to see if the object is able to follow
	if(this_object()->query_temp("is_unconcious") || this_object()->is_busy()) {
		return 1;
	}
	if( (origin()==ORIGIN_LOCAL) || (origin()==ORIGIN_CALL_OUT) ) {
//		this_object()->remove_all_enemy();		Holy, why ? successful go will remove enemy
		return GO_CMD->main(this_object(), dir);
	}
}

int follow_me(object ob, string dir)
{
	if( !living(this_object()) || ob==this_object() ) return 0;
	if( ob==leader
	||	(query("pursuer") && this_object()->is_killing(ob->query("id")))) {
		if( random(ob->query_skill("move")) > this_object()->query_skill("move") ) {
			remove_call_out("follow_path");
			call_out("follow_path", 1, dir);
			return 1;
		}
		return follow_path(dir);
	}
}

int add_team_member(object ob)
{
	string teamname;
	
	if( ob==this_object() ) return 0;

	if( arrayp(team) ) {
		if( member_array(ob, team)==-1 ) {
			team += ({ ob });
			ob ->set_temp("team_name",team[0]->query_temp("team_name"));
			for(int i=sizeof(team)-1; i>=0; i--)
				if(team[i])
				{
					team[i]->set_team(team);
				
				}
		} else
			return 0;
	} else {
		team = ({ this_object(), ob });
		ob->set_team(team);
		teamname = random_team_name();
		set_temp("team_name",teamname);
		ob->set_temp("team_name",teamname);
	}
	return 1;
}

int is_team_leader()
{
	return arrayp(team) && team[0]==this_object();
}

int set_team(object *t)
{
	team = t;
}

varargs int dismiss_team(object ob)
{
	int i;

	if( !arrayp(team) ) return 0;
	
	if( !ob ) {
		// if dismissed by leader, team disbands
		if( team[0]==this_object() ) {
			for(i=1; i<sizeof(team); i++)
				if(team[i]) {
					team[i]->set_team(0);
					team[i]->delete_temp("team_name");
				}
			delete_temp("team_name");	
		} else 
		// if dismissed by individual, kicked out
		{
			for(i=0; i<sizeof(team); i++)
				if(team[i] && team[i] != this_object())
				{
					team[i]->dismiss_team(this_object());
				}
			delete_temp("team_name");	// kinda redundant	
		}
		team = 0;
	} else
		{
			team -= ({ ob });
			ob->delete_temp("team_name");
		}

	return 1;
}

object *query_team()
{
	return team;
}

int 	team_member (object ob)
{
	if (!team || !sizeof(team))	return 0;
	if (member_array(ob, team) != -1)	
		return 1;
	else
		return 0;
}

//		you do the check outside :D
int	switch_team_member(object ob1, object ob2) {
	
	int i, j, k;
	object ob;
	
	if (!team_member(ob1) || !team_member(ob2))	return 0;
		
	for (i=0;i<sizeof(team);i++){
		if ( team[i] == ob1)	j=i;
		if ( team[i] == ob2)	k=i;
	}
	
	team[j] = ob2;
	team[k] = ob1;
	
	return 1;
}