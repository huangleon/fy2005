// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    mapping riddle;
    string *list, attr;
    object ob;
    int i,j, *num;

    if (wizardp(me) && stringp(arg))	
    {
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("��... ���������?\n");
    }else
	ob = me;

	riddle = ob->query("riddle");	 
    	
    write(WHT"\t����		" + ob->name()+ "���ڽ������\n"NOR);
    write(HIR BLK"������������������������������������������������������������������������������\n"NOR);

    if (!riddle)	write (HIR "��\n"NOR);
    else
    {
		list = keys(riddle);
		i = 0;					// deal with the problem of setting riddle=0
		for(j=0; j<sizeof(list); j++)
		{
		    if (riddle[list[j]])
		 	{
		    	if(i%5!=4) 
					write(sprintf(YEL"%-16s"NOR,list[j]));
		    	else 
					write(YEL + list[j] + "\n"NOR);   
				i++;
			}
		}
    }
    write(HIR BLK"\n������������������������������������������������������������������������������\n"NOR);
    
 
    riddle = ob->query("m_success");

    write(WHT"\t����		"+ob->name()+ "�Ѿ��⿪������\n"NOR);
    write(HIR BLK"������������������������������������������������������������������������������\n"NOR);

    if (!riddle)	write (HIR "��\n"NOR,16);
    else
    {
	list = keys(riddle);
	for(i=0; i<sizeof(list); i++)
	{
	    if(i%5!=4) 
		write(sprintf(CYN"%-16s"NOR,list[i]));
	    else
		write(CYN + list[i] + "\n"NOR);   
	}
    }
    write(HIR BLK"\n������������������������������������������������������������������������������\n"NOR);


    riddle = ob->query("imbue");

    write(WHT"\t����		" + ob->name()+ "�������ӵ�����\n"NOR);
    write(HIR BLK"������������������������������������������������������������������������������\n"NOR);

    if (!riddle)	write (HIR "��\n"NOR);
    else
    {
	list = keys(riddle);
	num = values(riddle);
	for(i=0; i<sizeof(list); i++)
	{
	    switch (list[i])
	    {
	    	case "agi": attr = "�ٶ�"; break;
	    	case "int": attr = "����"; break;
	    	case "con": attr = "����"; break;
	    	case "str": attr = "����"; break;
	    	case "cps": attr = "����"; break;
	    	case "kar": attr = "����"; break;
	    	default: attr = "";
	    }		
	    
	    if (sizeof (attr)>0)
		write(HIR + attr +" +" + num[i] + "\t"NOR);   
	}
    }
    write(HIR BLK"\n������������������������������������������������������������������������������\n"NOR);

    return 1;
}
int help(object me)
{
    write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	riddle            [0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ���������֪����Ŀǰ�Ѿ��⿪�����⣬�Լ���������ӵ�����

[0;1;37m����������������������������������������������������������������[0m  
HELP
    );
    return 1;
}


