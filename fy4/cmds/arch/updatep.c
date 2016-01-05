// updatep.c
// ¸¨Öú±àÒëÒ»¸öÄ¿Â¼ÏÂµÄ.cÎÄ¼ş

#include <ansi.h>
inherit F_CLEAN_UP;

int error;

int update_function(object me, string file);

int main(object me,string arg)
// arg should be /d/baiyun/ ....
{
    	string *files;
    	int i,total=0;
    	int size;
    	set_eval_limit(1); 
    	seteuid(getuid());
    	if(!arg || arg=="") return notify_fail("¸ñÊ½²»¶Ô£¡\n");
    
    	error = 0;
    	
    	write(HIW"ÕıÔÚËóÑ²"+arg+"ÎÄµµ¼Ğ£®£®£®\n"NOR);
    	
    	files= get_dir(arg);
    	reset_eval_cost();
    	for(i=0; i<sizeof(files); i++) 
    	{
    	    size=sizeof(files[i]);
        	if(files[i][(size-2)..size]==".c"){
        		if (files[i]=="updatep.c") continue;
        		total++;
				update_function(me, arg+files[i]);
			}	
//  	           	me->ccommand(sprintf("update %s%s",arg,files[i]));
        }   
        
        write(HIW"£®£®£®"+arg+"ÎÄµµ¼Ğ±àÒëÍê³É¡£
¡¡¡¡¡¡¹²ËóÑ²µ½"+total+"¸öµµ°¸£¬ÆäÖĞ"+error+"¸ö±àÒëÊ§°Ü¡£\n"NOR);	 	
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
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	updatep Ä¿Â¼Ãû	[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

updatep /d/baiyun/	¾ÍÊÇ±àÒëËùÓĞ/d/baiyun/Ä¿Â¼ÏÂµÄÎÄ¼ş¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
    );
    return 1;
}
