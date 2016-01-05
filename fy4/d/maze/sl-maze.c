// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room(__DIR__"sl-room");

	//�Թ��ĳ��Ϳ� (5-100)
	set_maze_long(25,25);
	
	//�趨�Թ���λ�����
	set_maze_spacing(5);

	//�Թ��������npc.
	//note: this one is optional
//	set_maze_npcs(__DIR__"npc/w-sentry-1");

	//�Թ������ڷ��� npc �Ŀ�����(1-100)
	//note: this one is optional too, if not set, then default is 20 (1/5)
//	set_maze_npc_rate(100);

	//�Թ��ؽ�ʱ�� pass in integer ����Ϊ��λ
	//note: this one is optional, if not set then default is no refresh
	//if pass in 0, then means no refresh too.
	// this example means maze will be refreshed in 1 hour.
//	set_maze_refresh(3600);

	//��ڷ���(�����ڶ���)
	set_entry_dir("west");

	//�������������ӷ���
	set_link_entry_dir("west");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"sl-entry");
	
	//��ڵ�����(��������link_entry_room���Ǹ���ʵroom������
	set_link_entry_room_x(0);
	set_link_entry_room_y(-100);
	set_link_entry_room_z(-10);
	

	//��������������ӷ���
	set_link_exit_dir("east");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"sl-exit");

	//��ڷ��������
	set_entry_short("һ������޺���");

	//��ڷ�������
	set_entry_desc(@LONG
�߹�ҹ���������ֵ�һ������޺��ã�ÿ�ö��е¸����أ����վ�տ����
�ָ�ɮ�ѳ֣�������ִ��������ִţ������˵ɮ�����潭��������֮ͽ�����գ���
��ͼı����˽�������ﲻ�����޺��ü��ǿ�֤ɮ���书�����ڣ�Ҳ�����ַ������
���صء�
LONG
);

	//���ڷ��������
	set_exit_short("�޺����");

	//���ڷ�������
	set_exit_desc(@LONG
����ǧ����࣬���ڴ��������Թ�һ���һ������޺��ã����������ɿ�����
ǰ����ǵ����������������ֵ����һ�ء�
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short("��¥�޵�");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
��¥��Ϊһ���񣬳���ׯ�ϱ�ɫ��ͷ��������Ϊ�����飬�����������࣬���� 
Ϊʳ������һ�������С���������գ������¶����޷��ٳԣ��������·����ߴΣ� 
�������ɽ�������ա���Ϊ��һ������Ϊʳ����ڻ�������࣬����ʱ���� 
�Է١�������ȥ��ֻ��һ�ģ�����������ɫ��
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(0);
}
