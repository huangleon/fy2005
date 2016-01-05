// udc.c annie 07.2003
// dancing_faery@hotmail.com
// ±àÒëÒ»¸öCLASSÏÂµÄÒ»ÇĞÎÄ¼ş
// ÓÃ"-o"À´±àÒë/DAEMON/SKILLÓë/DAEMON/CONDITIONÖĞµÄÒ»ÇĞÎÄ¼ş
// Ò»·½ÃæÎÒÃÇ²»ĞèÒªsilencerÄÇÑùÌ½¾¿µ½Ã¿¸ödirectoryµÄ×îµ×ÏŞ£»ÁíÒ»·½ÃæÓÖÒª±Èupdatep·½±ã¡£

#include <ansi.h>
inherit F_CLEAN_UP;

int error;

int update_function(object me, string file);

int main(object me,string arg)
{
	string *files;
	mixed *file;
	int i,j,w=0,col,total=0;
	int size;
	set_eval_limit(1); 
	seteuid(getuid());
	if(!arg || arg=="") return notify_fail("¸ñÊ½²»¶Ô£¡\n");

	error = 0;

	if (arg == "-o")
		arg = "/daemon/";
	else
		arg = "/daemon/class/"+arg+"/";
    
	file = get_dir(arg, -1);
   	reset_eval_cost();
	if( !sizeof(file) )
	{if (file_size(arg) == -2) return notify_fail("ÎÄµµ¼ĞÊÇ¿ÕµÄ¡£\n");
		else
		return notify_fail("Ã»ÓĞÕâ¸öÎÄµµ¼Ğ¡£\n");
	}

	write(HIW"ÕıÔÚËóÑ²"+arg+"ÎÄµµ¼Ğ£®£®£®\n"NOR);

	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) 
		{
			files = get_dir(arg+file[i][0]+"/");
		   	reset_eval_cost();
			// àÅ£¬Õâ¸öÓ¦¸ÃÊÇ¶ÔÓ¦µÄskillÎÄµµ£¬Ò»Æğ±àÒë°É
			update_function(me,"/daemon/skill/"+file[i][0]);
			// is a directory , ½ö×·ËİÒ»²ã¡£
			for(j=0; j<sizeof(files); j++) 
			{
				size=sizeof(files[j]);
				if(files[j][(size-2)..size]==".c")
				{
					update_function(me,arg+file[i][0]+"/"+files[j]);
					total++;
				}
			}   	 	
			file[i][0] += "/";
		}
	}
	write(HIW"£®£®£®"+arg+"ÎÄµµ¼Ğ±àÒëÍê³É¡£\n¡¡¡¡¡¡¹²ËóÑ²µ½"+total+"¸öµµ°¸£¬ÆäÖĞ"+error+"¸ö±àÒëÊ§°Ü¡£\n"NOR);

	return 1;	

}

int update_function(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("ÄãÒªÖØĞÂ±àÒëÊ²÷áµµ°¸£¿\n");

		file = resolve_path(me->query("cwd"), file);
		if( !sscanf(file, "%*s.c") ) file += ".c"; 

        if( file_size(file)==-1 )
                return notify_fail("Ã»ÓĞÕâ¸öµµ°¸¡£\n");

        me->set("cwf", file);

        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("Äã²»ÄÜÔÚ VOID_OB ÀïÖØĞÂ±àÒë VOID_OB¡£\n");
                }

                inv = all_inventory(obj);
                i = sizeof(inv);
                while(i--) {
                        if(userp(inv[i])) {
                        	inv[i]->move(VOID_OB, 1);
                        } else {
                        	destruct(inv[i]);
			}
                }

                destruct(obj);
        }

        if (obj) return notify_fail("ÎŞ·¨Çå³ı¾É³ÌÊ½Âë¡£\n");

    	write("ÖØĞÂ±àÒë " + file + "£º");
        err = catch( call_other(file, "???") );
        if (err)
		{
			error++;
                printf( "·¢Éú´íÎó£º\n%s\n", err );
			}
        else {
                write("³É¹¦£¡\n");
   		log_file( "UPDATE_LOG", sprintf("(%s)
%s updated %s\n", ctime(time()), me->query("name"), file));
        
        	if( (i=sizeof(inv)) && (obj = find_object(file))) {
        		while(i--)
                        	if( inv[i] && userp(inv[i]) ) 
					inv[i]->move(obj, 1);
                }
        }
                
        return 1;
}


int help(object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	udc [CLASSÃû] [-o]	[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

udc demon	±àÒëËùÓĞ/daemon/class/demon/ÏÂµÄÎÄ¼şÓë¶ÔÓ¦skills¡£
udc -o		±àÒëËùÓĞ/daemon/skill£¬/daemon/conditionÏÂµÄÎÄ¼ş¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
    );
    return 1;
}
