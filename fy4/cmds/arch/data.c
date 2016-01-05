//Copyright (C) 1996-2000 Apstone, Inc. All Rights Reserved.

// File : /cmds/wiz/data.c
// Last Modified : Mon Nov  9 22:49:16 1998

#include <dbase.h>
#include <ansi.h>

inherit F_DBASE;
int help(object me);

int main(object me, string arg)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    object ob, ob1;
    string text,*tmp, id, spec;
    int loop;

    //Security check??
    seteuid(geteuid(me));
    
    if (arg)
    {
        sscanf (arg, "%s %s", spec, arg);
        if (arg == "-t" || arg == "-d")
        {
            spec = arg;
            arg = 0;
        }
        if (spec && spec != "-d" && spec != "-t")
        {
            arg = spec + " " + arg;
            spec = 0;
        }
    }
    if(!arg || arg == "")  ob=me;
    else if (sscanf (arg, "%s in %s", arg, id) == 2)
    {
        ob1=present(id, environment(me));
        if (!ob1) ob1 = present(id, me);
        if (!ob1) return notify_fail ("Data�������޴�����: "+id+"\n");
        if (!ob=present(arg, ob1))
            return notify_fail ("Data�������������޴����: "+arg+"\n");
    }
    else if (arg == "here") ob = environment(me);
    else
    {
        arg = lower_case(arg);
        
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) ob = present(arg, me);
        if(!ob) return notify_fail("Data���޷��ҵ������: "+arg+"��\n");
    }
    
    list = (mapping)ob->query_entire_dbase();
    tlist = (mapping)ob->query_entire_temp_dbase();
    if( (!list || !mapp(list)) && (!tlist || !mapp(tlist)))
        return notify_fail("Data���������û���κε����ϡ�\n");
    
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
        return notify_fail("Data���������û�д����κ����ϡ�\n");
    
    if (!spec || spec == "-d")
    {
        text = HIW"�����" + base_name(ob) + ".c"NOR"\n";
        
        for(loop=0; loop<sizeof(klist); loop++)
        {
            if(strlen(klist[loop]) > 7)  text += klist[loop] + "\t: ";
            else text += klist[loop] + "\t\t: ";
            
            text +=sprintf("%O \n",list[ klist[loop] ]);
        }
        text += "\n"HIW"�ܹ��� " + sizeof(klist) + " ����������ϡ�"NOR"\n\n";
    }
    else text = "";
    
    if (!spec || spec == "-t")
    {
        text += HIW"�ݴ����ϣ�"NOR"\n\n";
 
        for(loop=0; loop<sizeof(tlist2); loop++)
        {
            if(strlen(tlist2[loop]) > 7)  text += tlist2[loop] + "\t: ";
            else text += tlist2[loop] + "\t\t: ";
            text +=sprintf("%O \n",tlist[ tlist2[loop] ]); 
        }
        
        text += "\n"HIW"�ܹ��� " + sizeof(tlist2) + " ���ݴ�����ϡ�"NOR"\n\n";
    }
    
    me->start_more("", text, 0);
    return 1;
}
 
//  This function is used to sort the key array. 
static int sort_keys(string one, string two)
{
    return strcmp(one, two);
}

int help(object me)
{
    write( @LONG
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	data [-t|-d] [���|���|here] [in ��һ�����][0m
[0;1;37m����������������������������������������������������������������[0m   

ָ��˵��:
    ������������Թۿ���ָ����������ϣ��ҽ����� more �ķ�ʽ
��������û��ָ���������Զ���ʹ����Ϊ���������е� -t ѡ���
����ʾ��ʱ����, -d ѡ�����ֻ��ʾ���ñ���, ��Ҫ���Ķ��������
��һ��κ����.

[0;1;37m����������������������������������������������������������������[0m   
LONG);
 
  return 1;
}
 
