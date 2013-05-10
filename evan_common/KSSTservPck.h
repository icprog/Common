/*
 * KSSTservPck.h
 *
 *  Created on: 2010-4-21
 *      Author: evantang
 */

#ifndef KSSTSERVPCK_H_
#define KSSTSERVPCK_H_

/* �����붨�� */
#define	CORRECT 			   (0)			//�����ȷ
#define	ParseKSSWordErr 	   (-1)			//�����ؼ���ʧ��
#define	WordLengthTooLong 	   (-2)			//�ؼ��ʹ���
#define	ResNumTooLarge 		   (-3)			//�����ѯ����Ŀ���ࣨ����300��
#define	NotEnoughBuff 		   (-4)			//Ϊ��ѯ����ķ���ռ䲻��
#define	NoResult			   (-5)			//��ѯ�޽��
#define	NoQuery 			   (-6)			//�޴˹ؼ���
#define	ParamError 			   (-7)			//����ʱ��������
#define	IndexError 			   (-8)			//������������������
#define MultiWordOverLoad      (-9)			//�����Ŀ��������
#define SectionOverLoad		   (-10) 		//���ȡ�ؽ��ʱҪ�����Ŀ����������

/*����Ϊproxy��search_server�ڲ�ͨ�Ŵ���*/
#define	ReceiveSearchHeadError (-100) 		//��SearchServer��ͷ����
#define	ReceiveSearchBodyError (-101) 		//��SearchServer�������
#define SendError              (-102)       //����ʧ��
#define ServerError			   (-103)       //���Ͷ�ʧ�ܵ�������
#define	Other 				   (-1000)		//�������
//}KSSWordErrorCode;

/***************************************** �����ֶ��� *****************************************/
						/*********����***********/
#define	ADDKSSWORD 							1	/*������*/
#define	SEARCHKSSWORDBYTIME 				2	/*�����ʰ�ʱ��ȡ���*/
#define	SEARCHKSSWORDBYRELATIVE 			7	/*�����ʰ������ȡ���*/
#define	SEARCHKSSWORDBYTIMEANDRELATIVE		4	/*�����ʸ���ʱ��ȡһ��ʱ�����������õ�n�����*/
#define	SEARCHKSSDOC						3	/*���ݴʺ�Docȡ���*/
#define	SEARCHMULTIKSSWORDBYTIMEWITHOUTMERGE    	6	/*����ʸ���ʱ�乲ȡm*n�����*/
#define	SEARCHMULTIKSSWORDBYRELATIVEWITHOUTMERGE    22	/*����ʸ�������Թ�ȡm*n�����*/
#define	SEARCHMULTIKSSWORDBYTIME			12	/*����ʰ�ʱ��ȡ���*/
#define SEARCHDOMAININFO                    20  /*��ѯ������Ϣ*/
#define SEARCHDOCSIZE						21  /*��ѯָ��doc���ֵ�λ����Ϣ�������ض�Ӧҳ����ĵ�����*/
#define SEARCHNEWSPOOLDOC                   23  /*���Ƽ������ų������ָ������Ϣ*/

#define SEARCHKSSTOPN						31  /*�����ų��������Ϣ*/
#define SEARCHKSSTOPNFORGOOD                32  /*�����ų�����ҽϺõ���Ϣ*/
#define SEARCHKSSTOPNOLD					30  /*�����ų��������Ϣ����Э��*/

#define SEARCHPROFILE 						33  /*����profile�ṩ�û�����Ȥ����*/

#define SEARCHWORDINRBU						15  /*��RBU��ȡ�´ʽ��������ǰ̨*/
#define SAVEWORDINRBU                       14  /*��RBUժȡ�´ʽ�������洢*/

						/*********���� �ղ�***********/
#define	GETSINGLEDOCID						3	/*������DocIdȡ�������*/
#define GETMULTIDOCID                       5   /*�����DocIdȡ�������*/

#define	SAVESINGLEDOCID 					9	/*������DocId��������*/
#define SAVEMULTIDOCID                      8   /*�����DocId��������*/

						/*********����ʹ��***********/
#define TESTFORSEARCHKSSWORDBYTIMEWITHOUTRBU 100
/***************************************** �����ֶ��� *****************************************/

/* Э��� */
#pragma pack(1)
struct recTservPckHead
{
	int length;			//�ܳ��ȣ�����ͷ������
	int cmd; 			//��ѯָ��
	int magic;			//��֤��

	recTservPckHead()
	{
		length = 0;
		cmd = 0;
		magic = 0;
	}
};


struct recRequestPck
{
	recTservPckHead head;
	char data[0];
};

struct recResponsePck
{
	recTservPckHead head;
	int ret;			//������
	char data[0];

	recResponsePck()
	{
		ret = 0;
	}
};

#pragma pack()

#endif /* KSSTSERVPCK_H_ */