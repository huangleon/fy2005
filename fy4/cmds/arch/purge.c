// purge.c

#include <ansi.h>
#define SYNTAX	"Ö¸Áî¸ñÊ½£ºpurge [<Î´ÉÏÏßÌìÊı>] | <Ê¹ÓÃÕßĞÕÃû> because <Ô­Òò>\n"

inherit F_CLEAN_UP;
int rmhirdir(string dir);
private int do_purge_players(int day);
int main(object me, string arg)
{
	string name, reason;
	string status;
	int day;

	status = wizhood(me);
	if( me!=this_player(1)
		|| wiz_level(me) < wiz_level(status))
		return notify_fail("ÄãÃ»ÓĞÈ¨Á¦Ê¹ÓÃÕâ¸öÖ¸Áî¡£\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%d", day) && day >= 30) return do_purge_players(day);

	if( sscanf(arg, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	if (reason == "bad")
		return notify_fail("ÇëÏêÏ¸Ğ´Ã÷É±µµÔ­Òò¡£\n");
		
	seteuid(getuid());
	
	if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + "/" + name + SAVE_EXTENSION)<0 )
		return notify_fail("Ã»ÓĞÕâÎ»Ê¹ÓÃÕß¡£\n");

	if( (string)SECURITY_D->get_status(name)!="(player)" )
		return notify_fail("²»ÄÜÖ±½ÓÉ¾³ı¹ÜÀíÈËÔ±µÄµµ°¸£¨Äã×Ü¸ÃÖªµÀÔõÃ´×ö°É£©¡£\n");

       	LOGIN_D->cphirdir(DATA_DIR + "login/" + name[0..0] + "/" + name, "/suicide/login/"+  "purged"+ name+time());
        LOGIN_D->cphirdir(DATA_DIR + "user/" + name[0..0] + "/" + name, "/suicide/user/"+ "purged"+ name + time());
        
      	rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
      	rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );

	write( "Ê¹ÓÃÕß " + capitalize(name) + " É¾³ıµôÁË¡£\n");
	write( "±»É¾³ıµÄµµ°¸±£´æÔÚsuicideÄ¿Â¼ÏÂ£¬ÒÔpurged" +  name + time() +"ÃüÃû¡£\n");
	
	log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	return 1;
}

private int do_purge_players(int day)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name;
	mixed info;
	int info2;

	seteuid(getuid());
	message("system", "\n*** ÕûÀíÍæ¼Ò´¢´æµµÖĞ£¬ÇëÉÔºò.... ***\n", users());
	write("´¦ÀíÖĞ£º");
	count = 0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		write(dir[i]);
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppl_cnt += sizeof(ppls);
		for(j=0; j<sizeof(ppls); j++) {
			if( sscanf(ppls[j], "%s", name)==1 )
				if( (string)SECURITY_D->get_status(name)!="(player)" )
					continue;
			info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j] +"/" +  ppls[j] + SAVE_EXTENSION);
			info2 = file_size(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]
			 +"/" +  ppls[j] + SAVE_EXTENSION);  
			if( info2 < 0 || time()-info[1] >= day*86400 ) {
				rmhirdir(DATA_DIR + "login/" + dir[i] + "/" + ppls[j] );
				rmhirdir(DATA_DIR + "user/" + dir[i] + "/" + ppls[j] );
				count ++;
			}
		}
	}
	write("\n\nÔ­À´×Ü¹²ÓĞ " + ppl_cnt + " Î»Ê¹ÓÃÕß¡£\n");
	write( count + " ¸ö³¬¹ı " + day + " ÌìÎ´ÉÏÏßµÄÊ¹ÓÃÕß±»Çå³ıµôÁË¡£\n");
	write("ÏÖÔÚ×Ü¹²ÓĞ " + (ppl_cnt - count) + " Î»Ê¹ÓÃÕß¡£\n");
	log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
		"\t\tResulting statistics: %d characters remaining.\n",
		ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));


	return 1;
}


int rmhirdir(string dirstr)
{
string *dir;
int i;
dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
		if(file_size(dirstr+"/"+dir[i]) == -2 ) {
				rmhirdir( dirstr +"/"+dir[i]);
				rmdir(dirstr+"/"+dir[i]);
						}
		rm(dirstr+"/"+dir[i]);
	}
rmdir(dirstr);

return 1;

}
int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : purge [<Î´ÉÏÏßÌìÊı>] | <Ê¹ÓÃÕßĞÕÃû> because <Ô­Òò>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Çå³ıÒ»¸öÊ¹ÓÃÕß»òÇå³ı³¬¹ıÒ»¶¨ÌìÊı²»ÔøÉÏÏßµØÊ¹ÓÃÕß¡£
ÏÖÔÚ°Ñpurgedµµ°¸Ò²±¸·İÏÂÀ´ÒÔÁô¼ÍÂ¼¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
	);
    return 1;
}

