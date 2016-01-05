// team.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

static object leader, *team;

string random_team_name(){
	string *lname = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ","½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ðí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ð","Îº","ÌÕ","½ª","ÆÝ","Ð»","×Þ","Ó÷","°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ð","ÞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ý","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø","µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂÞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶","Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ð¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ","Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ÐÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô","ÓÝ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","Íò","ºò","Ë¾Âí",
"ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ð","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦","Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ",
"×ÚÕþ","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå","ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ðù","Áîºü","ÖÓÀë","ÓîÎÄ",
"³¤Ëï","Ä»ÈÝ","Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕý","ÈÀæá","¹«Á¼",
"ÍØÖº","¼Ð¹È","Ô×¸¸","¹ÈÁº","³þ½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ","¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù",
"ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÔÀ","Ë§","çÃ","¿º","¿ö","ºó","ÓÐ","ÇÙ","ÁºÇð","×óÇð","¶«ÃÅ","Î÷ÃÅ",
	});
	return lname[random(200)] + "¼Ò°ï";
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